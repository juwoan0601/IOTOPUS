from bluetooth import *
import argparse

parser = argparse.ArgumentParser(description='Process some integers.')
parser.add_argument('--msg', type=str, help='message to send by bluetooth')
args = parser.parse_args()

#BLUETOOTH_PAIR_KEY = "98:D3:71:F9:B8:8B" # LED
BLUETOOTH_PAIR_KEY = "98:D3:71:F9:B8:37" # SERVO

if __name__ == '__main__':
    socket = BluetoothSocket( RFCOMM )
    socket.connect((BLUETOOTH_PAIR_KEY, 1))
    print("bluetooth connected!")
    socket.send(args.msg)
    socket.close()