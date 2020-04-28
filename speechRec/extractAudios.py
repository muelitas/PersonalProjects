'''************************************************************
  * File:    extractAudios.C
  * Author:  Mario Esparza
  * Date:    04/27/2020
  * 
  * Given a video and a csv file, this program reads the csv
  * file and extracts audios from the video. The csv files must
  * contain the start time and end time of each audio that is
  * desired to be extracted. 
  TODO finish this description
  *
  * Tested in PopOS 18.04 LTS
  * 
  * References:
  * - https://gist.github.com/jaivikram/4690569
  *
*************************************************************'''

def getAudioSpecs(videoPath):
    tmpf = tempfile.NamedTemporaryFile()
    os.system("ffmpeg -i \"%s\" 2> %s" % (videoPath, tmpf.name))
    lines = tmpf.readlines()
    tmpf.close()
    #TODO: Find out how to dynamically obtain bit depth.
    sr, channels, bitDepth = 0, 0, 16
    for l in lines:
        l = l.strip() #remove white spaces
        L = l.decode("utf-8") #convert from bytes to string
        if L.startswith('Stream #0:1'):
            #Get sample rate
            if (re.search(', (.*? Hz),', L)):
                SR = re.search(', (.*? Hz),', L).group(1)
                sr = int(SR[:-3])
            else:
                print("Couldn't find sampling rate")
            
            #Get number of channels
            if(re.search(', stereo,', L)):
                channels = 2
            elif(re.search(', mono,', L)):
                channels = 1
            else:
                print("Num of channels is not 2, nor 1")
    
    values = {"sr":sr,"channels":channels,"bitDepth":bitDepth}
    return values

thisdict =	{
  "brand": "Ford",
  "model": "Mustang",
  "year": 1964
}

import moviepy
from moviepy import editor
from moviepy.editor import *
import pandas as pd
#import numpy as np
from scipy.io.wavfile import write
#import soundfile as sf
import os
#import sys
import re
import tempfile

filepath = "//media//mario//GRAYUSB//Research//Current//MVI_0011.MP4"
specs = getAudioSpecs(filepath)


#Specify paths
videoPath = ""
csvpath = ""
destPath = ""

#Specify path of video
videoPath = "//media//mario//GRAYUSB//Research//Current//MVI_0011.MP4"
#Specify pathname of folder where sliced audios will be saved
destPath = "//home//mario//Desktop//Temporary"
#Specify pathname of csv where GT information is stored
csvpath = "//media//mario//GRAYUSB//Research//Current//Datasets//Aolme_006//info.csv"

#Read csv file into dataframe; then, convert to Python lists
data = pd.read_csv(csvpath, usecols=['starttimes', 'endtimes'])
myDict = data.to_dict()
temp = myDict['starttimes']
starttimes=list(temp.values())
temp = myDict['endtimes']
endtimes = list(temp.values())

video = VideoFileClip(videoPath) #get the video
audio = video.audio #get the audio in the video
clip = audio.subclip(float(starttimes[0]), float(endtimes[0]))
clip2 = clip.to_soundarray(fps=specs['sr'], nbytes=int(specs['bitDepth']/8))

#If channels is 2 or more, choose only the first channel (make it mono)
if(int(specs['channels']) > 1):
    data = clip2[:,0]
else:
    data = clip2

counter = 1
filename = "{:05d}_".format(counter)
filename = filename+'_'+str(int(specs['sr']/1000))+'K' #append samplerate
filename = filename+'_'+str(len(data.shape))+'CH' #append numOfChannels
filename = filename+'_'+str(specs['bitDepth'])+'B' #append bitDepth info
filename = filename + '.wav'
write(destPath + '//' + filename, specs['sr'], data)


#sf.write(filename, data, 48000, 'PCM_16')
/home/mario/Desktop/Temporary/00001__48K_1CH_16B.wav
#TODO finish program
'''


for i in range(len(starttimes)):
    print("index = {}".format(i)+" starttime={}".format(starttimes[i])
          + " endtime={}".format(endtimes[i]))
'''
