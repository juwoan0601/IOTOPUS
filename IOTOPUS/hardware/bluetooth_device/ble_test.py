from bluetooth import *

socket = BluetoothSocket( RFCOMM )
socket.connect(("98:D3:71:F9:B8:8B", 1))
print("bluetooth connected!")

while True:
    data = socket.recv(1024)
    print("Received: %s" %data)
    if(data.decode(ascii)=="q"):
        print("Quit")
        break

socket.close()