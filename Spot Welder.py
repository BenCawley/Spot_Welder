import RPi.GPIO as GPIO
from time import sleep

def setup():
	GPIO.setmode(GPIO.BCM)
	GPIO.setup(4, GPIO.IN, pull_up_down=GPIO.PUD_UP) # Pedal
	GPIO.setup(15, GPIO.OUT, initial=0) # Relay
	GPIO.setup(17 , GPIO.OUT, initial=0) # Red LED
	GPIO.setup(27 , GPIO.OUT, initial=1) # Green LED
	GPIO.setup(22 , GPIO.OUT, initial=0) # Blue LED

def closure():
	RelayDelay = 0.015
	MainPulse = 0.05 + RelayDelay
	FirstPulse = (MainPulse * 0.12) + RelayDelay
	GPIO.output(27, 0)
	GPIO.output(17, 1)

	GPIO.output(15, 1)
	sleep(FirstPulse)
	GPIO.output(15, 0)

	GPIO.output(17, 0)
	GPIO.output(22, 1)
	sleep(0.5)

	GPIO.output(22, 0)
	GPIO.output(17, 1)

	GPIO.output(15, 1)
	sleep(MainPulse)
	GPIO.output(15, 0)

	GPIO.output(17, 0)
	GPIO.output(27, 1)

setup()

GPIO.add_event_detect(4, GPIO.RISING, callback=closure, bouncetime=1000)
