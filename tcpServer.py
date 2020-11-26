import socket

#en este programa recibes la conexion del otro programa y recibes 1024 bits
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

#con 000 dices que vas a ocupar cualquier interfaz de red (Ip )que tenga tu computadora
#puerto origen 1337 o 
s.bind(("0.0.0.0",1337))

#escuchar una conexion a la vez
s.listen(1)

#aceptar conexion
conn, addr = s.accept()

#con esto se cierra la conexion
with conn:
    dataFromClient = conn.recv(1024)
    print(dataFromClient)
    conn.send(b"OK")