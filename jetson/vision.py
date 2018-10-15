from collections import deque
import numpy as np
import argparse
import imutils
import cv2

# code that does vision processing
class Vision:

    # takes an arbitrary amount of controllers, which will be set off here in the
    # vision processing loop
    def __init__(self, camera_index, commander, left_right_controller, forward_back_controller):
        self.command = commander
        self.lr_controller = left_right_controller
        self.fb_controller = forward_back_controller

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
        while True:
            (grabbed, frame) = camera.read()

            frame = imutils.resize(frame, width=600)
            blurred = cv2.GaussianBlur(frame, (11, 11), 0)
            hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

            mask = cv2.inRange(hsv, greenLower, greenUpper)
            mask = cv2.erode(mask, None, iterations=2)
            mask = cv2.dilate(mask, None, iterations=2)

            cnts = cv2.findContours(mask.copy(), cv2.RETR_EXTERNAL,
                                cv2.CHAIN_APPROX_SIMPLE)[-2]
            center = None

            if len(cnts) > 0:
                c = max(cnts, key=cv2.contourArea)
                ((x, y), radius) = cv2.minEnclosingCircle(c)
                M = cv2.moments(c)
                center = (int(M["m10"] / M["m00"]), int(M["m01"] / M["m00"]))


                if radius > 10:
                    # draw the circle and centroid on the frame,
                    # then update the list of tracked points
                    cv2.circle(frame, (int(x), int(y)), int(radius),
                        (0, 255, 255), 2)
                    cv2.circle(frame, center, 5, (0, 0, 255), -1)

            # update the points queue
            self.pts.appendleft(center)
            
            left, right = self.lr_controller.control(self.pts.popleft()[0])
            self.command.left(left)
            self.command.right(right)



