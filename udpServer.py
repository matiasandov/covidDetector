import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind(("0.0.0.0",1337))
dataFromClient = s.recv(1024)
print(dataFromClient)