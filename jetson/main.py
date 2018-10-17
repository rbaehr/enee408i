from controller import Controller
from left_right_controller import LeftRightController
from command import Command
from vision import Vision

def main():
    c = LeftRightController(300)
    command = Command(serial_port='/dev/ttyACM1')
    vision = Vision(command, c, None)

    vision.loop()


if __name__ == '__main__':
    main()
