'''************************************************************
  * File:     cropVideo.py
  * Author1:  Mario Esparza
  * Author2:  Luis Sanchez
  * Date:     05/23/2020
  * 
  * Using moviepy, we extract a subclip from a video given the
  * start and end (in seconds) of the desired subclip.
  *
  * Tested in PopOS 18.04 LTS
  *
*************************************************************'''
import moviepy
from moviepy import editor
from moviepy.editor import *

pathToVideo = '/home/mario/Desktop/G-C2L1P-Feb16-D-Chaitu_02-05.MP4'
subClipFolder = '/home/mario/Desktop'

Clip = VideoFileClip(pathToVideo)
FPS = Clip.fps
start = 680 #in seconds
end = 900 #in seconds

subClip = Clip.subclip(start, end)
subClipPath = subClipFolder + '/video2.MP4'
subClip.write_videofile(subClipPath,codec='libx264',fps=FPS)