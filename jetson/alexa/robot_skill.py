import logging
import sys
sys.path.append('..')
from random import randint
from flask import Flask, render_template
from flask_ask import Ask, statement, question, session

from controller import Controller
from left_right_controller import LeftRightController
from forward_back_controller import ForwardBackController
from command import Command
from vision import Vision

c1 = LeftRightController(300, 0.25)
c2 = ForwardBackController(40, 0.2)
command = Command(serial_port='/dev/ttyACM0')
vision = Vision(command, c1, c2, camera_index=0)

app = Flask(__name__)
ask = Ask(app, "/")
logging.getLogger("flask_ask").setLevel(logging.DEBUG)


@ask.launch
def new_game():
    welcome_msg = render_template('welcome')
    return question(welcome_msg)

@ask.intent("Recognize")
def recognize():

    name = vision.recognize()
    if len(name) == 0:
        recognize_msg = render_template('recognize_none')
    if len(name) == 1:
        recognize_msg = render_template('recognize_one', name=name)
    else:
        pass

    return question(recognize_msg)

if __name__ == '__main__':

    app.run(debug=True)
