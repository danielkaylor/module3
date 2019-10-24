import socket
import RPi.GPIO as GPIO
import time

UDP_IP = "192.168.1.2"
UDP_PORT = 57222

sock = socket.socket(socket.AF_INET, # Internet
                    socket.SOCK_DGRAM) # UDP
sock.bind((UDP_IP, UDP_PORT))

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(16, GPIO.OUT)
GPIO.setup(13, GPIO.OUT)
GPIO.setup(21, GPIO.OUT)

while True:
	data, addr = sock.recvfrom(1024) # buffer size is 1024 bytes
	print("received message: {}".format(data))

	if int(data) == 0:
		GPIO.output(18, GPIO.HIGH)
		GPIO.output(16, GPIO.HIGH)
		GPIO.output(13, GPIO.HIGH)
		GPIO.output(21, GPIO.HIGH)
	else:
		GPIO.output(18, GPIO.LOW)
		GPIO.output(16, GPIO.LOW)
		GPIO.output(13, GPIO.LOW)
		GPIO.output(21, GPIO.LOW)
