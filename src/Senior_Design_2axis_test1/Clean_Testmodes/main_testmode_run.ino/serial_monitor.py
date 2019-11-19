import serial
from datetime import datetime

# device name and rate
dev_name = ""
rate = 9600

# serial declaration to interfce with teh device
s = serial.Serial(port=dev_name, baudrate=rate)

# serial input array to collect the information and post it to a file
serial_input = []
data = ""


try:
    s.open()

    print("Reading in Serial Input on device %s" % (dev_name))
    while (s.is_open()):
        data = s.readline()
        serial_input.append(data)
        print(data)


finally:
    # close the serial port
    s.close()


f = None

try:
    # open a file and write information to that file
    f = open(str(datetime.now()), "w")
    
    for i in serial_input:
        f.write(str(f) + "\n")

finally:
    f.close()

