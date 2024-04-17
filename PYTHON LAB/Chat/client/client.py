# client.py

import socket

host = '127.0.0.1'
port = 5500

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))

try:
    while True:
        msg = input("From Client: ")
        if msg == 'exit':
            break
        s.send(msg.encode())
        data = s.recv(1024)
        print("Message From Server: " + data.decode())
except KeyboardInterrupt:
    print("Client disconnecting...")
finally:
    s.close()