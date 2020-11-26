import socket
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("172.16.38",1337))
s.send()