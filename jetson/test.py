import serial
import struct


ser = serial.Serial('/dev/ttyACM0', 9600)

ser.close()
ser.open()

left = struct.pack('>h', -1)
right = struct.pack('>h', -1)

ser.write(left)
ser.write(right)
a = ser.readline()
b = ser.readline()

print(a, b)
