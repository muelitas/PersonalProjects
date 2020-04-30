'''************************************************************
  * File:    obtainMFCCs.py
  * Author:  Mario Esparza
  * Date:    04/28/2020
  * 
  * Given a directory with sub-directories containing audios, iterate
  * through each audio. Extract Mel Frequency Cepstral Coefficients
  * (MFCCs) and store them in matrix (X) as an npy file. Program 
  * checks that all audios share the same sample rate. It ignores files
  * that are under .5 seconds. If audios are between .5 and .99 seconds,
  * they are "expanded" to a 1 second-long audio using zero padding.
  *
  * Tested in PopOS 18.04 LTS
  *
*************************************************************'''
#Get # of audio files; check if sr is the same among them; determine how many
#   columns X will have
def getDetails(directory):
    counter, sr, cols = 0, np.inf, np.inf
    for item in sorted(os.listdir(directory)):
        sub_dir = directory + '//' + item
        for subitem in sorted(os.listdir(sub_dir)):
            audio_path = sub_dir + '//' + subitem
            samplerate, samples = read(audio_path)
            
            #If audios don't share same sr, these two if's will notify you
            if(counter == 0):
                sr = samplerate
            if(sr != samplerate):
                print("Warning, sample rates among your audios do not match.")
                print("Mismatch catched with file: "+audio_path)
                
            #If audio's duration is <= .5secs, ignore audio
            duration = len(samples)/samplerate
            if(duration > 0.5):
                counter = counter + 1
    
    #Create dummy audio to determine # of columns
    dummyAudio = np.zeros([sr])
    mfccs = librosa.feature.mfcc(dummyAudio, sr=samplerate, n_mfcc=13)
    mfccs = mfccs[1:]   #only grab 2 to 13, ignore 1st mfcc
    cols = mfccs.shape[0] * mfccs.shape[1]
    
    return sr, counter, cols

import os, os.path
from scipy.io.wavfile import read
import numpy as np
import librosa

parent_dir = '//home//mario//Desktop//Temporary'
SR, numOfFiles, ncols = getDetails(parent_dir)
nrows = numOfFiles
#Declare before-hand how large X and y will be
X = np.zeros([nrows, ncols])
y = np.zeros([nrows]) #labels

#Iterate through folders and extract features (MFCCs) from audios
i = 0
for item in sorted(os.listdir(parent_dir)):
    sub_dir = parent_dir + '//' + item
    for subitem in sorted(os.listdir(sub_dir)):
        audio_path = sub_dir + '//' + subitem
        samplerate, samples = read(audio_path)
        duration = len(samples)/samplerate
        
        #Ignore audios <= .5secs 
        if(duration > 0.5):
            tempData = np.zeros([SR])
            if(duration >= 1):
                #Only grab 1 second worth of samples
                tempData = samples[0:SR]
            else: 
                tempData[0:len(samples)] = samples
                
            #Calculate, reshape and save MFCCs in X (feature extraction)
            mfccs = librosa.feature.mfcc(tempData, sr=samplerate, n_mfcc=13)
            mfccs = mfccs[1:]   #only grab 2 to 13, ignore 1st mfcc
            X[i,0:] = mfccs.reshape((1,ncols), order='F') #reshape to row vector
            i = i + 1

#Save X and y as npy files
X_path = parent_dir + '//X.npy'
y_path = parent_dir + '//y.npy'
np.save(X_path, X)
np.save(y_path, y)
