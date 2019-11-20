import serial
from datetime import datetime

# device name and rate
dev_name = "/dev/ttyUSB1"
rate = 9600

# serial declaration to interfce with teh device
s = serial.Serial(port=dev_name, baudrate=rate)

# serial input array to collect the information and post it to a file
serial_input = []
data = ""


try:
    if s.isOpen():
        print("Device is already opened...\n%s" % (dev_name))
    else:
        s.open()

    print("Reading in Serial Input on device %s" % (dev_name))
    while (s.isOpen()):
        data = s.readline().decode()
        serial_input.append(data)
        print(data)

except KeyboardInterrupt:
    print("Pressed CTL+C")

finally:
    # close the serial port
    if (s.isOpen()):
        print("Device is still in use somewhere else...")
    else:
        s.close()


f = None

try:
    # open a file and write information to that file
    f = open(str(datetime.now()), "w")
    
    for i in serial_input:
        f.write(str(i) + "\n")

finally:
    f.close()

