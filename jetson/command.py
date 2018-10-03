import serial

class Command:

    def __init__(self, serial_port='/dev/TTY0', baud_rate=9600):
        self.ser = serial.Serial(serial_port, baud_rate)

    def write_command(self, left, right):
        self.ser.write(left)
        self.ser.write(right)

    def read_command(self):
        return self.serial.readline()
