'''************************************************************
  * File:     get_audio_specs.py
  * Author1:  Mario Esparza
  * Author2:  Luis Sanchez
  * Date:     07/03/2020
  * 
  * This program iterates through list of audio files and uses
  * ffmpeg to get specs from each one of them. It returns the
  * sample rate, number of channels, bit depth and bit rate of
  * each audio. Currently, we have only tested it in wav files.
  * 
  * Tested in PopOS 18.04 LTS
  * 
  * Reference for Regular Expressions:
  * https://docs.python.org/3/howto/regex.html#regex-howto
  *
*************************************************************'''
import re
import tempfile
import os

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

#List audios of interest
paths = ['path1.WAV',\
         'path2.WAV',\
         'path3.WAV',\
         'etc.WAV']

#Prints sampleRate, numOfChannels, bitDepth and bitRate of each audio
for path in paths:
    values = getAudioSpecs(path)
    print(f'{values}\n')
    