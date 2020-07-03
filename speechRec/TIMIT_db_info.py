'''************************************************************
  * File:     TIMIT_db_info.py
  * Author1:  Mario Esparza
  * Author2:  Luis Sanchez
  * Date:     07/02/2020
  * 
  * This program iterates through all files in TIMIT dataset. It
  * saves paths of those that contain information of phonemes.
  * It then iterates through these files, scans line by line of
  * each file and keeps track of:
  *     - How many times a phoneme is scanned
  *     - The length of each scanned phoneme
  * When done with the iterations and the scanning, it plots a
  * histogram representing the different lengths and how many
  * times each length was recorded. It also plots a bar graph of
  * each phoneme and the times it was encountered in the dataset
  
  * Tested in PopOS 18.04 LTS
  *
  * Reference of TIMIT's Database:
  * Garofolo, John S., et al. TIMIT Acoustic-Phonetic Continuous
  * Speech Corpus LDC93S1. Web Download. Philadelphia: Linguis-
  * tic Data Consortium, 1993.
  *
*************************************************************'''
import numpy as np
import os
import matplotlib.pyplot as plt

#Loop through "parents" folders and get phonemes-docs' full-paths
parents = ['TRAIN','TEST']
phn_paths = []
timit_path = '/media/mario/GRAYUSB/Research/Current/Phonemes/TIMIT'
for parent in parents:
    parent_path = timit_path + '/' + parent
    for item in sorted(os.listdir(parent_path)):
        child_dir_path = parent_path + r'/' + item
        for subitem in sorted(os.listdir(child_dir_path)):
            subdirectory = child_dir_path + r'/' + subitem
            for filename in sorted(os.listdir(subdirectory)):
                if filename.endswith(".PHN"):
                    phn_file = subdirectory + r'/' + filename
                    phn_paths.append(phn_file)

#Local Variables
numOfFiles = len(phn_paths)
phonemesCounter = {} #records how many times a phoneme is scanned
numOfSamples = list() #records the number of samples of each phoneme
i = 0

#Iterate through phoneme files
while(i<numOfFiles):
    hsharpCounter = 0;      #keeps track of the number of 'h#'
    phn_path = phn_paths[i]
    file = open(phn_path, 'r')
    #Iterate through lines in phoneme file
    while(1):
        line = file.readline()
        line2 = line.split(' ')
        if(line2[2] == 'h#\n'):
            hsharpCounter += 1
            #If end of file, break loop and move to next .phn file
            if(hsharpCounter == 2):
                file.close()
                break
        else:
            phoneme = line2[2]
            phoneme = phoneme[:-1]
            #If phoneme hasn't been recorded, update dictionary
            if(phoneme not in phonemesCounter.keys()):
                phonemesCounter[phoneme] = 0
            
            #Add number of scans for "phoneme" by 1
            phonemesCounter[phoneme]+=1
            #Append its number of samples
            numOfSamples.append(int(line2[1]) - int(line2[0]))
                
    i += 1  #move to next .phn file
    
#Sort numOfSamples to create histogram
Nsamples = np.sort(numOfSamples)
histSamples= np.zeros(int(Nsamples[-1])+1)
for j in Nsamples:
    histSamples[int(j)] = histSamples[int(j)] + 1

#Plot Histogram
plt.figure(figsize=(15,5))
plt.plot(histSamples)
plt.title("Histogram showing how long all phonemes are and how many times \
each length is repeated")
plt.ylabel('Num of Samples')
plt.xlabel('Num of Repetitions')
plt.show()

#Plot Bar Graph that represents how many times each phoneme was encountered
labels  = phonemesCounter.keys()
x = np.arange(len(labels))
numOfScans = phonemesCounter.values()
plt.figure(figsize=(25,5))
plt.title("Bar graph showing phonemes encountered in dataset, as well as \
the number of times they were encountered")
plt.bar(x, numOfScans)
plt.xticks(x, labels)
plt.show()