class Nodes:
    def __init__(self, Name, Address):
        self.range = 250
        self.address = Address
        self.id = Name
        self.Neighbors = []
        self.sending = False
        self.recieving = False
    
    def Recieve(self, sender):
        if self.recieving == False:
            print(f'{self.id} Recieving message from {sender}')
            self.recieving = True
        else:
            print('Unable to recieve message COLLISION')
            print('HIDDEN TERMNAL PROBLEM \n')
    
    def Transmit(self, receiver):
        print(f'\n{self.id} sending message to {receiver.id}')
        if receiver not in self.Neighbors:
            print('Node out of range')
        else:
            for node in self.Neighbors:
                if node.sending == True:
                    print('Unable to send message, neighbor sending, waiting for timeout')
                    print('EXPOSED TERMINAL PROBLEM')
                    self.sending = True
                    break
                
            if self.sending == False :
                self.sending = True
                receiver.Recieve(self.id)
                
    
def main():    
    A = Nodes('A', 450)
    B = Nodes('B', 850)
    C = Nodes('C', 650)
    D = Nodes('D', 1050)
    
    for i in [B , C, D]:
        if abs(i.address - A.address) < A.range:
            A.Neighbors.append(i)
            i.Neighbors.append(A)
    
    for i in [C, D]:
        if abs(i.address - B.address) < B.range:
            B.Neighbors.append(i)
            i.Neighbors.append(B)
            
    if abs(D.address - C.address) < C.range:
        C.Neighbors.append(D)
        D.Neighbors.append(C)
        
    B.Transmit(C)
    A.Transmit(D)
    A.Transmit(C)
    C.Transmit(A)
    
if __name__ == '__main__':
    main()
    