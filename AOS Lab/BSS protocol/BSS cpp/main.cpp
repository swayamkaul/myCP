#include <iostream>
#include "process.h"

Message createMessage(std::string data, int parentId){
    Process::processes[parentId].timeState[parentId]++;
    std::cout << "Process[" << parentId+1 << "] Creating Message:" << data << std::endl;
    return Message(data,Process::processes[parentId].timeState, parentId);
}

void printClockState(unsigned int id){
    std::cout << "Process[" << id+1 << "]: {";
    for(auto i:Process::processes[id].getTimeState()){
        std::cout << i << ' ';
    }
    std::cout << "}" << std::endl;
}

void printClockState(){
    for(int id = 0; id < Process::processes.size(); id++){
        std::cout << "Process[" << id+1 << "]: {";
        for(auto i:Process::processes[id].getTimeState()){
            std::cout << i << ' ';
        }
        std::cout << "\b}\n";
    }
    std::cout.flush();
}

int main(){
    Process::createProcesses(3);
    printClockState();
    Message msg1 = createMessage("Hello, World! I am P3", 2);
    printClockState();
    Process::processes[2].sendMessage(msg1, 1);
    printClockState();
    Message msg2 = createMessage("Hello, World! I am P2, I recieved Message 1, but when i sent this message, P1 hadn't recieved Message 1 yet", 1);
    printClockState();
    Process::processes[1].sendMessage(msg2, 0);
    printClockState();
    Process::processes[1].sendMessage(msg2, 2);
    printClockState();
    Process::processes[2].sendMessage(msg1, 0);
    printClockState();
    Message msg3 = createMessage("Hello, World! I am P1, I recieved Both messages from P1 and P2", 0);
    printClockState();
    Process::processes[0].broadcast(msg3);
    printClockState();
}