import serial 
import argparse
import keyboard
import pyautogui
import time

def print_serial(name):
    try:
        serial_port = serial.Serial(port='COM4', baudrate=9600, timeout=1)
        print(f"The Port name is {serial_port.name}")
        start = 0
        while True:
            lines = serial_port.readline()
            string = lines.decode()
            if(string == "P\n"):
                print("shoot")
                if(time.time() - start >= 0.1):
                    keyboard.press_and_release("l")
                    start = time.time()
    except Exception as e:
        print("ERROR")
        print(e)
        exit() 

# ap = argparse.ArgumentParser()
# ap.add_argument("-p","--port",required = True, help = "Enter Port Name")
# args = vars(ap.parse_args())

PORT = "COM4"

print_serial(PORT)