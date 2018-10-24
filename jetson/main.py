from controller import Controller
from left_right_controller import LeftRightController
from forward_back_controller import ForwardBackController
from command import Command
from vision import Vision

def main():
    c1 = LeftRightController(300, 0.25)
    c2 = ForwardBackController(40, 0.2)
    command = Command(serial_port='/dev/ttyACM0')
    vision = Vision(command, c1, c2)

    vision.loop()


if __name__ == '__main__':
    main()
