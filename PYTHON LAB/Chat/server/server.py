# server.py

import socket

host = '127.0.0.1'
port = 5500

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((host, port))
s.listen(1)
print("Server Connected......Waiting for client...")
c, addr = s.accept()
print("Client Connected")

try:
    while True:
        msg = c.recv(1024)
        if not msg:
            break
        print("Message From Client: " + str(msg.decode()))
        response = input("From Server: ")
        c.send(response.encode())
except KeyboardInterrupt:
    print("Server shutting down...")
finally:
    c.close()
    s.close()
