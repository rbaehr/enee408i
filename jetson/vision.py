from collections import deque
import numpy as np
import imutils
import cv2

# code that does vision processing
class Vision:

    # takes an arbitrary amount of controllers, which will be set off here in the
    # vision processing loop
    def __init__(self, commander, left_right_controller, forward_back_controller,
                 camera_index=1, moving_average=10):
        self.command = commander
        self.moving_average = moving_average
        self.lr_controller = left_right_controller
        self.fb_controller = forward_back_controller

        # lower and upper boundaries of the "green" in HSV
        self.greenLower = (29, 86, 6)
        self.greenUpper = (64, 255, 255)

        # if a video path was not supplied, use the webcam
	self.camera = cv2.VideoCapture(camera_index)

    def loop(self):
        pts = []
	radi = []
        while True:
            for i in xrange(self.moving_average):
                (grabbed, frame) = self.camera.read()

                frame = imutils.resize(frame, width=600)
                blurred = cv2.GaussianBlur(frame, (11, 11), 0)
                hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

                mask = cv2.inRange(hsv, self.greenLower, self.greenUpper)
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


                if center is None:
                    #center = (0, 0)
                    continue
                pts.append(center)
		radi.append(radius)
                #print(center)

	    len_pts = len(pts)
	    len_radi = len(radi)
            pts_avg = 0
	    r_avg = 0
            for _ in pts:
                pts_avg += pts.pop()[0]
	
	    for _ in radi:
		r_avg += radi.pop()

            pts_avg /= len_pts
            pts_avg = int(pts_avg)
	    r_avg /= len_radi
	    r_avg = int(r_avg)

            left, right = self.lr_controller.control(pts_avg)
            print(left, right, radius)
            self.command.left(left)
            self.command.right(right)



