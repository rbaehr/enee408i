from controller import Controller
from left_right_controller import LeftRightController
from command import Command

def main():
    c = Controller(1)
    c1 = LeftRightController(2)

    print(c.p)
    print(c1.p)


if __name__ == '__main__':
    main()
