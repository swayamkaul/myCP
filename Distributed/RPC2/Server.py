import socket

def add(x,y):
    return x + y

def sub(x,y):
    return x - y

Host = '192.168.24.168'
port = 5786

mySocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket Creation Success\n')

mySocket.bind((Host, port))
print('Socket bind Successful! Port: ',port)

mySocket.listen()
print('Server is listening')

conn, addr = mySocket.accept()
print('Connected to ', addr)
conn.send('Successfully Connected to Client'.encode())
    
while True:        
    data = conn.recv(1024).decode()
    print('Client :',data)
    if data == 'close()':
        mySocket.close()
        break
    if data[0:4] == 'add(':
        x, y = '', ''
        i = 4
        while data[i] != ',':
            x += data[i]
            i += 1
        y += data[i+1:-1]
        xint= int(x)
        yint = int(y)
        txt = str(add(xint,yint))
        print('Server: ',txt)

    else:
        if data[0:4] == 'sub(':
            x, y = '', ''
            i = 4
            while data[i] != ',':
                x += data[i]
                i += 1
            y += data[i+1:-1]
            xint= int(x)
            yint = int(y)
            txt = str(sub(xint,yint))
            print('Server: ',txt)
        else:
            txt = input('Server: ')
    conn.send(txt.encode())
    


