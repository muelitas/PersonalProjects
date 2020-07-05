'''************************************************************
  * File:     chop_audios_from_video.py
  * Author1:  Mario Esparza
  * Author2:  Luis Sanchez
  * Date:     04/27/2020
  * 
  * Given a video and a csv file, this program reads the csv
  * file and extracts audios from the video. The csv files must
  * contain the start time and end time of each audio that is
  * desired to be extracted. If the original audio of the video
  * has PCM codec, chopped audios are saved as .wav files.
  * Otherwise, they are saved as .mp3 files.
  *
  * Tested in PopOS 18.04 LTS
  * 
  * References:
  * - https://gist.github.com/jaivikram/4690569
  *
*************************************************************'''
from moviepy.editor import VideoFileClip
from moviepy.audio import *
import pandas as pd
import os
import re
import tempfile

def getAudioSpecs(audioFile):
    """Return audio's sample rate, num of channels, bit rate and bit depth"""
    #Initialize specs that will be returned
    sr, channels, bitDepth, bitRate = 0, 0, 0, 0
    
    #Create temporary file and get ALL info of file
    tmpf = tempfile.NamedTemporaryFile()
    os.system("ffmpeg -i \"%s\" 2> %s" % (audioFile, tmpf.name))
    lines = tmpf.readlines()
    tmpf.close()
    
    #Prints all information of the file
    #print(lines)
    
    #Iterate through each line to find audio's information
    for l in lines:
        l = l.strip() #remove white spaces
        L = l.decode("utf-8") #convert from bytes to string
        
        #If audio is found in file, get all aforementioned specs
        if L.startswith('Stream #0:1'):
            #Prints information related only to the audio
            #print(L)
            
            #Check if audio is PCM
            isAudioPCM = bool()
            if(re.search(': pcm(.*?),', L)):
                isAudioPCM = True
            
            #Get sample rate
            if (re.search(', (.*? Hz),', L)):
                SR = re.search(', (.*? Hz),', L).group(1)
                sr = int(SR[:-3])
            else:
                print("Couldn't find sampling rate")
                sr = -1
            
            #Get number of channels
            if(re.search(', stereo,', L)):
                channels = 2
            elif(re.search(', mono,', L)):
                channels = 1
            else:
                print("Num of channels is not 2, nor 1")
                channels = -1
                
            #Get bit depth only if audio is PCM
            #https://en.wikipedia.org/wiki/Audio_bit_depth
            if(re.search(', s(.*?),', L) and isAudioPCM):
                BitDepth = re.search(', s[0-9]+[\w]*,', L).group(0)
                print(f"Found BitDepth: {BitDepth}")
                bitDepth = BitDepth[2:-1]
            else:
                print("Couldn't find bit depth")
                bitDepth = -1              
                
            #Get bit rate
            if(re.search(', ([0-9]*? kb/s)', L)):
                BitRate = re.search(', ([0-9]*? kb/s)', L).group(1)
                bitRate = int(BitRate[:-5])
            else:
                print("Couldn't find bit rate")
                bitRate = -1
            
    values = {"sr":sr,"channels":channels,"bitRate":bitRate,"bitDepth":bitDepth}
    return values

#Path for video of interest
videoPath = ""
#Folder where chopped audios will be saved
csvpath = ""
#CSV containing start and end times
destPath = ""

#Read csv file as dataframe; then, convert to Python lists
data = pd.read_csv(csvpath, usecols=['starttimes', 'endtimes'])
myDict = data.to_dict()
temp = myDict['starttimes']
starttimes=list(temp.values())
temp = myDict['endtimes']
endtimes = list(temp.values())

#Get video and specs of its audio
video = VideoFileClip(videoPath)
specs = getAudioSpecs(videoPath)
#Get audio from video
audio = video.audio

#Naming convention; to each file name I append its sampleRate, number of
#channels, bitDepth and bitRate
filename = '_'+str(int(specs['sr']/1000))+'K' #append samplerate
filename = filename+'_'+str(len(data.shape))+'CH' #append numOfChannels
filename = filename+'_'+str(specs['bitRate'])+'kbs' #append bitRate info
#If original audio's codec is PCM, append bitDepth info, otherwise don't
if(specs['bitDepth'] != -1):
    filename = filename+'_'+str(specs['bitDepth'])+'B'

#Iterate through start and end times
for i in range(len(starttimes)):
    start = float(starttimes[i])
    end = float(endtimes[i])
    
    #Chop audio
    clip = audio.subclip(start, end)
    #Append counter to filename
    fileName = "{:05d}".format(i+1) + filename
    
    #Save audio as wav file if original audio's codec is PCM
    if(specs['bitDepth'] != -1):
        fileName = destPath + '//' + fileName + '.wav'
        clip.write_audiofile(destPath + '//' + fileName, fps=specs['sr'],\
            nbytes=int(specs['bitDepth']/8), codec='libmp3lame',\
            bitrate=str(specs['bitRate'])+'K')
    else: #Otherwise, save as mp3
        fileName = destPath + '//' + fileName + '.mp3'
        clip.write_audiofile(fileName, fps=specs['sr'],\
            codec='libmp3lame', bitrate=str(specs['bitRate'])+'K')