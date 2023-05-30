import serial
import serial.tools.list_ports


# connector = serial.Serial(port='COM9', baudrate=9600, timeout=1)

# print("hi")
# while True:
#     print(connector.readline().decode('utf-8'))
#     connector.write(bytes('1', 'utf-8'))
#     # print(connector.readline().decode('utf-8'))



connector = serial.Serial(port='COM8', baudrate=9600)
while True:
    connector.write(bytes('1', 'utf-8'))
