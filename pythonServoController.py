#!/usr/bin/env python

################################################
# Module:   servo.py
# Created:  2 April 2008
# Author:   Brian D. Wendt
#   http://principialabs.com/
# Version:  0.3
# License:  GPLv3
#   http://www.fsf.org/licensing/
'''
Provides a serial connection abstraction layer
for use with Arduino "MultipleSerialServoControl" sketch.
'''
################################################

import serial
import time

# Assign Arduino's serial port address
#   Windows example
#     usbport = 'COM3'
#   Linux example
#     usbport = '/dev/ttyUSB0'
#   MacOSX example
#     usbport = '/dev/tty.usbserial-FTALLOK2'
usbport = '/dev/tty.usbmodem1451'

# Set up serial baud rate
ser = serial.Serial(usbport, 9600)
time.sleep(4)

def move(angle):
    '''Moves the servo to the supplied angle.

    Arguments:
        angle
          the desired servo angle, an integer from 0 to 180

    (e.g.) >>> servo.move(90)
           ... # "move servo to 90 degrees"'''

    if (0 <= angle <= 180):
        print angle
        ser.write(chr(255))
        ser.write(chr(angle))
        time.sleep(1)
        myData = ser.readline()
        print myData

    else:
        print("Servo angle must be an integer between 0 and 180.\n")

for i in range (1, 100):
    move(10)


#myData = ser.readline()
#print(myData)
#print 'hei'
