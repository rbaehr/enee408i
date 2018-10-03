from collections import deque
import numpy as np
import argparse
import imutils
import cv2

# code that does vision processing
class Vision:

    # takes an arbitrary amount of controllers, which will be set off here in the
    # vision processing loop
    def __init__(self, camera_index, *controllers):
        self.controllers = controllers

    # lower and upper boundaries of the "green" in HSV
    self.greenLower = (29, 86, 6)
    self.greenUpper = (64, 255, 255)

    # initialize the list of tracked points, to draw the ball trayectory
    self.pts = deque(maxlen=args["buffer"])

    # if a video path was not supplied, use the webcam
    if not args.get("video", False):
        self.camera = cv2.VideoCapture(1)

    # otherwise, grab a reference to the video file
    else:
        camera = cv2.VideoCapture(args["video"])


    def loop(self):
        

