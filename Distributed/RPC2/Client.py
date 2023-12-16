import socket

Host = '192.168.24.125'
port = 5788

mySocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket Creation Success\n')

mySocket.connect((Host, port))
print('Socket bind Successful! Port: ',port)
mySocket.send('Client Connected'.encode())
print(mySocket.recv(1024).decode())

while True:
    
    txt = mySocket.recv(1024).decode()
    print('Server :',txt)
    data = input('Client : ')
    mySocket.send(data.encode())
    if data == 'close()':
        break