import logging
import threading, time, socket
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

PORT = 9001

c1 = LeftRightController(300, 0.25)
c2 = ForwardBackController(40, 0.2)
command = Command(serial_port='/dev/ttyACM0')
vision = Vision(command, c1, c2)

app = Flask(__name__)
ask = Ask(app, "/")
logging.getLogger("flask_ask").setLevel(logging.DEBUG)


@ask.launch
def new_game():
    welcome_msg = render_template('welcome')
    return question(welcome_msg)

@ask.intent("Recognize")
def recognize():

    lst = vision.recognize()
    #names = ['Ross', 'Joseph']

    if len(lst) == 0:
        recognize_msg = render_template('recognize_none')
    elif len(lst) == 1:
        recognize_msg = render_template('recognize_one', name=lst[0])
    elif len(lst) == 2:
        recognize_msg = render_template('recognize_two', name1=lst[0], name2=lst[1])
    else:
        recognize_msg = render_template('recognize_many', names=lst[1:], final=lst[0])

    return question(recognize_msg)

@ask.intent("Chase")
def chase():

    vision.follow_ball()
    welcome_msg = render_template('welcome')
    return question(welcome_msg)

@ask.intent("Forward")
def forward():
    command.forward(45)
    time.sleep(3)
    command.stop()
    welcome_msg = render_template('direction')
    return question(welcome_msg)


@ask.intent("Backward")
def backward():
    command.backward(45)
    time.sleep(3)
    command.stop()
    welcome_msg = render_template('direction')
    return question(welcome_msg)



@ask.intent("Turn")
def turn(direction):
    d = str(direction).lower()
    if d == 'left':
        command.turn_left(35)
    elif d == 'right':
        command.turn_right(35)

    time.sleep(2)
    command.stop()
    welcome_msg = render_template('direction')
    return question(welcome_msg)

def dispense_pill():
    s = socket.socket()
    s.connect((command.host, PORT))

    for _ in range(6):
            s.send('go'.encode('utf-8'))
            print('loop')
            time.sleep(2)


@ask.intent("Dispense")
def dispense():
    command.dispense_pill()
    threading.Thread(target=dispense_pill).start()
    dispense_msg = render_template('dispense')
    return question(dispense_msg)


@ask.intent("AMAZON.FallbackIntent")
def fallback():
    fallback_msg = render_template('fallback')
    return question(fallback_msg)

if __name__ == '__main__':

    app.run(debug=True)
