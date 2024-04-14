FQBN = arduino:avr:uno
FILE = pelletizer.ino
PORT = COM8

all: compile upload

compile:
	@arduino-cli compile --fqbn $(FQBN) $(FILE)

upload:
	@arduino-cli upload -p $(PORT) --fqbn $(FQBN) $(FILE)
