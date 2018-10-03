# python code to control Arduino
# Receive position and size data from image processing
# Convert to output signals for the arduino.
# have to send data over serial, right?

# need to include MATH and PYSERIAL
import math, pyserial

def movement_control(size, position):
# check for the position
# if it's close enough to center, drive forward with maybe a little turning.
# if it's not, turn toward the ball first, then drive forward.
    center = 100 # position value in the middle of the screen
    difference = position - center
    centered_width = 5 # fow far on each side of center the position can be and still be close enough to drive forward
    close_width = 15
    target_size = 50
    long_distance_size = 20
    factor = 50
    if math.fabs(difference) < centered_width: # pointed close to straight, go forward
        if size < target_size: # not close enough, go forward
            right_speed = 8
            left_speed = 8
        # go forward by setting both motor speeds forward
        if size > target_size: # got too close
            right_speed = 4
            left_speed = 4
        # go back a little
        if size < long_distance_size: # it's really far away
            right_speed = 12
            left_speed = 12
        # go faster
        if size == target_size:
            right_speed = 6
            left_speed = 6

        if math.fabs(differece) < close_width and math.fabs(difference) > centered_width: # not quite centered, but close
        if difference > 0: # ball is on the right
            right_speed = 7
            left_speed = 10
        #both wheels forward, left wheel a little faster
        if difference < 0: # ball on left
            right_speed = 10
            left_speed = 7
        #both wheels forward, right wheel faster

        if math.fabs(difference) > close_width:
            scaled = (difference - centered_width)/factor #downscale the difference to a value around 0 +/- 6
            if right_speed > 12:
                right_speed = 12
            if right_speed < 0:
                right_speed = 0
            if left_speed > 12:
                left_speed = 12
            if left_speed < 0:
                left_speed = 0

    control_data = 16*left_speed + right_speed
    ser.write(control_data)

#if math.abs(difference) < centered_width #absolute value of difference is less than centered_width
#    slow_turn(difference)
#else
#    fast_turn(difference)
