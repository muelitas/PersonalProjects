function [esTSNR, esHRNR]=WienerNoiseReduction(ns,fs,initialSilence)
% function [esTSNR,esHRNR]=WienerNoiseReduction(ns,fs,initialSilence)

% [esTSNR,esHRNR]=WIENERNOISEREDUCTION(ns,fs,initialSilence)
%
% Title  :      Wiener Noise Suppressor with TSNR & HRNR algorithms
%
% Description : Wiener filter based on tracking a priori SNR using Decision-Directed 
%               method, proposed by Plapous et al 2006. The two-step noise reduction
%               (TSNR) technique removes the annoying reverberation effect while
%               maintaining the benefits of the decision-directed approach. However,
%               classic short-time noise reduction techniques, including TSNR, introduce
%               harmonic distortion in the enhanced speech. To overcome this problem, a
%               method called harmonic regeneration noise reduction (HRNR)is implemented
%               in order to refine the a priori SNR used to compute a spectral gain able 
%               to preserve the speech harmonics.
%               
% 
% Reference :   Plapous, C.; Marro, C.; Scalart, P., "Improved Signal-to-Noise Ratio
%               Estimation for Speech Enhancement", IEEE Transactions on Audio, Speech,
%               and Language Processing, Vol. 14, Issue 6, pp. 2098 - 2108, Nov. 2006 
%
% Input Parameters :  
%   ns          Noisy speech 
%   fs          Sampling frequency (in Hz)
%   initialSilence          Initial Silence (or non-speech activity) Period (in number of samples)
%
% Output Parameters : enhanced speech  
%   esTSNR      enhanced speech with the Two-Step Noise Reduction method 
%   esHNRN      enhanced speech with the Harmonic Regeneration Noise Reduction method
%             
%Author :       LIU Ming, 2008
%Modified :     SCALART Pascal october, 2008
%
%

%% ------- input noisy speech  --------

signalLength = length(ns);

frameLength = fix(0.020*fs);                   % window length is 20 ms
NFFT = 2*frameLength;                          % FFT size is twice the window length
hanWin = hanning(frameLength);                 % Use Hanning window to minimize Gibbs phenomenon of frames

% Did user provide silence index when function was called
if (nargin < 3 | isstruct(initialSilence))
    % Initial Silence or Noise Only part in samples (= ten frames)
    initialSilence = 10*frameLength;           
end

%% -------- compute noise statistics ----------
% Reserve and initialize memory for the summation terms
P_n1_n2 = zeros(NFFT,1);           
frameCount = 0; 

for frameNumber = 0:initialSilence-frameLength
  frame = ns(frameNumber+(1:frameLength)).*hanWin; % Minimize Gibbs phenomenon  
  P_n1_n2 = P_n1_n2 + abs(fft(frame,NFFT)).^2;     % Compute frame PSD
  frameCount = frameCount + 1;
end

% Average the squared power over the number of frames used
P_n1_n2 = P_n1_n2/frameCount;
invP_n1_n2 = ones(size(P_n1_n2))./P_n1_n2;

%% --------- main algorithm ---------------
SP = 0.25;      % Shift percentage is 50 % Overlap-Add method works good with this value
normFactor = 1/SP;
overlap = fix((1-SP)*frameLength); % overlap between sucessive frames
offset = frameLength - overlap;
numberOfFrames = fix((signalLength-NFFT)/offset);

oldMag = zeros(NFFT,1);
filteredSignal = zeros(signalLength,1);

phasea=zeros(NFFT,numberOfFrames);
xmaga=zeros(NFFT,numberOfFrames);
tSNRa=zeros(NFFT,numberOfFrames);
newMags=zeros(NFFT,numberOfFrames);

alpha = 0.75;

%Iteration to remove noise
%% --------------- TSNR ---------------------
for frameNumber = 0:numberOfFrames
   indexBegin = frameNumber*offset+1;    
   indexEnd = frameNumber*offset+frameLength;
   
   frame = ns(indexBegin:indexEnd);  % Recover frame
   
   [postSNR, magFrame, phaseFrame] = calculatePostSNR(frame, NFFT, hanWin, invP_n1_n2);

   %calculate a priori SNR using decision directed approach
   eta = alpha * (oldMag.*invP_n1_n2) + (1-alpha) * postSNR;
   newMag = (eta./(eta+1)).*magFrame;
   
   %calculate TSNR
   tSNR = (newMag.^2).*invP_n1_n2;
   gain_tSNR = tSNR./(tSNR+1);         %gain of TSNR    
   %Gtsnr=max(Gtsnr,0.1);  
   gain_tSNR = gaincontrol(gain_tSNR,int32(NFFT/2));
   
   newMag = gain_tSNR .* magFrame;
   oldMag = abs(newMag).^2;
   
   %for HRNR use
   newMags(:,frameNumber+1) = oldMag;     
   phasea(:,frameNumber+1) = phaseFrame;         
   xmaga(:,frameNumber+1) = magFrame;
   tSNRa(:,frameNumber+1)= gain_tSNR; 
   
   % Apply phase correction
   fftFrame = newMag.*exp(1i*phaseFrame);
   
   filteredSignal(indexBegin:indexBegin+NFFT-1) = filteredSignal(indexBegin:indexBegin+NFFT-1) + real(ifft(fftFrame,NFFT))/normFactor;
end

esTSNR=filteredSignal;
%% --------------- HRNR -----------------------

%non linearity
newHarm= max(esTSNR,0);
filteredSignal = zeros(signalLength,1);
%
for frameNumber = 0:numberOfFrames
   indexBegin = frameNumber*offset+1;    
   indexEnd = frameNumber*offset+frameLength;

   frameHarm = newHarm(indexBegin:indexEnd);     % Recover frame
   frameHarm = hanWin.*frameHarm;                % Minimize Gibbs phenomenon of truncated signal
   magFrame = abs(fft(frameHarm,NFFT)).^2;   % Perform fast fourier transform
  
   alpha =  tSNRa(:,frameNumber+1);
   postSNR = magFrame.*invP_n1_n2;
   snrHarm= alpha.*newMags(:,frameNumber+1).*invP_n1_n2 + (1-alpha).*postSNR;
   
   newGain = (snrHarm./(snrHarm+1));
   %newgain=max(newgain,0.1);  
   
   newGain=gaincontrol(newGain,NFFT/2);
   
   newMag = newGain.*xmaga(:,frameNumber+1);
 
   fftFrame = newMag.*exp(1i*phasea(:,frameNumber+1));
   
   filteredSignal(indexBegin:indexBegin+NFFT-1) = filteredSignal(indexBegin:indexBegin+NFFT-1) + real(ifft(fftFrame,NFFT))/normFactor;
end

%Output
esHRNR = filteredSignal;

blueSepia = gray(64).^0.8;
blueSepia(:,1:2) = blueSepia(:,1:2) * 0.5;
blueSepia = [flipud(blueSepia) ; hot(64)];

figure;
  [B,f,T] = specgram(ns,NFFT,fs,hanWin,frameLength-10);
  imagesc(T,f,20*log10(abs(B))); axis xy; colorbar
  title(['Spectrogram - noisy speech'])
  xlabel('Time (sec)');ylabel('Frequency (Hz)');
  ylim([0 2000])
  set(gca,'FontSize',14,'FontWeight','bold')
  colormap(blueSepia)
 
figure;
  [B,f,T] = specgram(esTSNR,NFFT,fs,hanWin,frameLength-10);
  imagesc(T,f,20*log10(abs(B))); axis xy; colorbar
  title(['Spectrogram - output speech TSNR'])
  xlabel('Time (sec)');ylabel('Frequency (Hz)');
  ylim([0 2000])
  set(gca,'FontSize',14,'FontWeight','bold')
  colormap(blueSepia)
 
figure;
 [B,f,T] = specgram(esHRNR,NFFT,fs,hanWin,frameLength-10);
 imagesc(T,f,20*log10(abs(B))); axis xy; colorbar
 title(['Spectrogram - output speech HRNR'])
 xlabel('Time (sec)');ylabel('Frequency (Hz)'); 
 ylim([0 2000])
 set(gca,'FontSize',14,'FontWeight','bold') 
 colormap(blueSepia)

function [postSNR, magFrame, phaseFrame] = calculatePostSNR(frame, NFFT, hanWin, invP_n1_n2)

   frame = hanWin.*frame;                    % Minimize Gibbs phenomenon of truncated signal
   fftFrame = fft(frame,NFFT);               % perform fast fourier transform
   phaseFrame = angle(fftFrame);             % extract phase
   magFrame = abs(fftFrame);                 % extract magnitude

   postSNR = ((magFrame.^2).*invP_n1_n2)-1 ; % calculate a posteriori SNR
   %postsnr = max(postSnr,0.1);    % limitation to prevent distortion

function NewGain=gaincontrol(Gain,ConstraintInLength)
%
%Title  : Additional Constraint on the impulse response  
%         to ensure linear convolution property
%
%
%Description : 
%
% 1- The time-duration of noisy speech frame is equal to L1 samples.
%
% 2- This frame is then converted in the frequency domain 
%       by applying a short-time Fourier transform of size NFFT leading
%       to X(wk) k=0,...,NFFT-1 when NFFT is the FFT size.
%
% 3- The estimated noise reduction filter is G(wk) k=0,1,...,NFFT-1 
%       leading to an equivalent impulse response g(n)=IFFT[G(wk)] 
%       of length L2=NFFT
%
% 4- When applying the noise reduction filter G(wk) to the noisy 
%       speech spectrum X(wk), the multiplication S(wk)=G(wk)X(wk) is
%       equivalent to a convolution in the time domain. So the
%       time-duration of the enhanced speech s(n) should be equal to 
%       Ltot=L1+L2-1.
%
% 5- If the length Ltot is greater than the time-duration of the IFFT[S(wk)] 
%       the a time-aliasing effect will appear.
%
% 6- To overcome this phenomenon, the time-duration L2 of the equivalent
%       impulse response g(n) should be chosen such that Ltot = L1 + L2 -1 <= NFFT 
%       => L2 <= NFFT+1-Ll
%
%       here we have NFFT=2*Ll so we should have L2 <= Ll+1. I have made
%       the following choice : the time-duration of g(n) is limited to
%       L2=NFFT/2=L1 (see lines 88 and 192)
%
%Author : SCALART Pascal
%
%October  2008
%


meanGain=mean(Gain.^2);
NFFT=length(Gain);

L2=int32(double(ConstraintInLength)/2)*2;

win=hamming(L2);

% Frequency -> Time
% computation of the non-constrained impulse response
ImpulseR=real(ifft(Gain));

% application of the constraint in the time domain
ImpulseR2=[ImpulseR(1:L2/2).*win(1+L2/2:L2);
           zeros(NFFT-L2,1);
           ImpulseR(NFFT-L2/2+1:NFFT).*win(1:L2/2)];

% Time -> Frequency
NewGain=abs(fft(ImpulseR2,NFFT));

meanNewGain=mean(NewGain.^2);

NewGain=NewGain*sqrt(meanGain/meanNewGain); % normalisation to keep the same energy (if white r.v.)


   
