import serial
import time
import random
import os

if __name__ == '__main__':
    os.system("arduino-cli compile --fqbn arduino:avr:mega")
    os.system("arduino-cli upload --fqbn arduino:avr:mega --port /dev/ttyACM0")

    ser = serial.Serial('/dev/ttyACM0', 9600, timeout=1)
    ser.reset_input_buffer()

    while True:
        randRed = chr(random.randint(0, 255))
        randGreen = chr(random.randint(0, 255))
        randBlue = chr(random.randint(0, 255))
        print(str.encode(randRed) + str.encode(randGreen) + str.encode(randBlue))
        ser.write(str.encode(randRed) + str.encode(randGreen) + str.encode(randBlue))
        # line = ser.readline().decode('utf-8').rstrip()
        # print(line)
        time.sleep(1)