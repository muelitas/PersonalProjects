%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%{
% File:         WienerCleanAudios.m
% Author1:  Mario Esparza
% Author2:  Luis Sanchez
% Date:       05/28/2020
% 
% The purpose of this file is to read an audio and remove background
% noise (clean the audio). We do so with a Wiener Filter (below you
% can find the reference to such) that uses two methods: Two-Step 
% Noise Reduction and Harmonic Regeneration Noise Reduction.
% 
% We first read the audio. Then, we split into left and right channels.
% Then, we pass each channel through the filter. When done, we 
% bring both channels together and save the resulting audios. One
% audio for each method.
%
% Reference :   Plapous, C.; Marro, C.; Scalart, P., "Improved Signal-to-Noise Ratio
%               Estimation for Speech Enhancement", IEEE Transactions on Audio, Speech,
%               and Language Processing, Vol. 14, Issue 6, pp. 2098 - 2108, Nov. 2006 
%
% Tested in MATLAB R2019b
%}
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
clear variables;
close all;
clc;

%Specify source and destination paths
audioPath = "C:\Users\Mario\Desktop\WienerCleaningAudios\00005__48K_2CH_16B.wav";
dest = extractBefore(audioPath,".wav");
dest1 = insertAfter(dest, strlength(dest),'_TSNR.wav'); %enhanced speech using Two-Step Noise Reduction 
dest2 = insertAfter(dest, strlength(dest),'_HRNR.wav'); %enhanced speech using Harmonic Regeneration Noise Reduction

%Read audio and its sample rate
[original,Fs] = audioread(audioPath);

%Use Wiener on left channel, then on right -> combine -> save
[samplesLength,numOfChannels] = size(original);
if numOfChannels == 2
    %Left Channel First
    orig_LCH = original(:,1);
    [TSNR_left, HRNR_left]=WienerNoiseReduction(orig_LCH,Fs);

    %Right Channel Second
    orig_RCH = original(:,2);
    [TSNR_right, HRNR_right]=WienerNoiseReduction(orig_RCH,Fs);

    %Combine Channels and Save (TSNR case)
    if length(TSNR_right) == length(TSNR_left)
        TSNR = zeros(length(TSNR_right), 2);
        TSNR(:,1) = TSNR_left;
        TSNR(:,2) = TSNR_right;
        audiowrite(dest1,TSNR,Fs);
    else
        message = 'left and right channels of TSNR do not share same length';
        disp(message);
    end

    %Combine Channels and Save (HRNR case)
    if length(HRNR_right) == length(HRNR_left)
        HRNR = zeros(length(HRNR_right), 2);
        HRNR(:,1) = HRNR_left;
        HRNR(:,2) = HRNR_right;
        audiowrite(dest2,HRNR,Fs);
    else
        message = 'left and right channels of HRNR do not share same length';
        disp(message);
    end
else
    message = 'This program only works with stereo audios (2-channel audios)';
    disp(message);
end

%Use this line of code to check characteristics of an audio file
%info = audioinfo(audioPath);

%Use this line of code to listen to audio
%sound(TSNR_left,Fs,16);
