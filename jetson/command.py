import serial, struct, time, socket

PORT = 9001

class Command:

    def __init__(self, serial_port='/dev/ttyACM0', baud_rate=9600):
        try:
            self.ser = serial.Serial(serial_port, baud_rate)
            self.ser.flushInput()
            self.ser.flushOutput()
        except:
            pass

        self.LEFT_CW_CMD = 0x01
        self.LEFT_CCW_CMD = 0x02
        self.RIGHT_CW_CMD = 0x04
        self.RIGHT_CCW_CMD = 0x08
        self.PING_CMD = 0xF0

        with open('config/hostname', 'r') as f:
            for i in f:
                hostname = str(i)

        self.s = socket.socket()
        self.s.connect((hostname, PORT))


    def dispense_pill(self):
        for _ in range(6):
            self.s.send('go'.encode('utf-8'))
            time.sleep(2)


    def write_command(self, opcode, operand):
        self.ser.write(struct.pack('>B', opcode))
        self.ser.write(struct.pack('>B', operand))


    def left(self, speed):
        if speed >= 0:
            self.write_command(self.LEFT_CW_CMD, speed)
        else:
            self.write_command(self.LEFT_CCW_CMD, abs(speed))

    def right(self, speed):
        if speed >= 0:
            self.write_command(self.RIGHT_CW_CMD, speed)
        else:
            self.write_command(self.RIGHT_CCW_CMD, abs(speed))

    def ping(self):
        self.write_command(self.PING_CMD, 0)

        dist = []
        for i in xrange(3):
            dist.append(int(self.ser.readline().strip()))

        return dist



    def read_command(self):
        return self.serial.readline()
