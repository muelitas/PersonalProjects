'''************************************************************
  * File:     cropVideo.py
  * Author1:  Mario Esparza
  * Author2:  Luis Sanchez
  * Date:     05/23/2020
  * 
  * Using moviepy, we extract a subclip from a video given the
  * start and end (in seconds) of the desired subclip. Note
  * that the cropped video may not have the same configuration
  * as the original one; i.e. kbps may result different, codec
  * may result different, audio's SR may also result different.
  * For a more reliable cropping, I have used the .sh file in
  * this folder called "crop_video.sh".
  *
  * After running .sh file, I run the following instruction:
  * 	ffmpeg -i input.MP4 -ss 00:00:00 -to 00:00:00 -c:v
  * 	libx264 -b:v 24500K -maxrate 26000K -bufsize 12000K -c:a
  * 	aac -b:a 256K output.MP4
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
