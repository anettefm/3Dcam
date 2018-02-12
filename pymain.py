import serial #Import Serial Library

arduinoSerialData = serial.Serial('/dev/tty.usbmodem1451',9600) #Create Serial port object called arduinoSerialData

myData = arduinoSerialData.readline()
print myData
