import socket
import marshal

Host = '192.168.24.125'
port = 5786

my_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
print('Socket Created')
my_socket.connect((Host, port))
print('Socket binded to port ',port)
my_socket.send('Connected'.encode())
print(my_socket.recv(1024).decode())

d = {'nums1' : 0 , 'nums2' : 0 , 'sum' : 0}
while True:
    txt = my_socket.recv(1024).decode()
    print('Server :',txt)
    data1 = input('Client : ')
    my_socket.send(data1.encode())
    
    txt = my_socket.recv(1024).decode()
    print('Server :',txt)
    data = input('Client : ')
    my_socket.send(data.encode())
    
    d['nums1'] = int(data1)
    d['nums2'] = int(data)
    
    byte = marshal.dumps(d)
    my_socket.send(byte)
      
    res = my_socket.recv(1024)
    sol = marshal.loads(res)
    ans = sol['sum']
    
    print('Server :',ans)
    break
