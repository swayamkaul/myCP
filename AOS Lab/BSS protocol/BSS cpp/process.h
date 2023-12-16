#ifndef BSS_PROCESS_H_
#define BSS_PROCESS_H_

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

#include "message.h"

class Process{
private:
    unsigned int n;
    std::vector<Message> buffer;
    std::vector<unsigned int> timeState;
    Process(int id, unsigned int n):n(n),id(id),timeState(n,0){}

    unsigned int delta(std::vector<unsigned int> & vc){
        unsigned int d = 0;
        for(int i = 0; i < n; i++){
            if(vc[i]!=timeState[i]){
                d+= vc[i]>timeState[i]?vc[i]-timeState[i]:timeState[i]-vc[i];
            }
        }
        return d;
    }

    void recieveMessage(Message msg){
        std::cout << "Process[" << id+1 << "]: Recieved Message from " << msg.sender+1 << std::endl;
        if(msg.timeStamp[id]==timeState[id]+1){
            processMessage(msg);
        }
        else{
            buffer.push_back(msg);
        }
        sort(buffer.begin(), buffer.end(), [&](Message& a, Message& b){return delta(a.timeStamp)>delta(b.timeStamp);});
        unsigned int senderId = msg.sender;
        while(buffer.size() && delta(buffer.back().timeStamp)==1){
            processMessage(buffer.back());
            buffer.pop_back();
        }
    }

public:
    unsigned int id;
    inline static std::vector<Process> processes;

    static void createProcesses(unsigned int n){
        processes.reserve(n);
        for(int i = 0; i < n; i++){
            processes.push_back(Process(i,n));
        }
    }

    std::vector<unsigned int> & getTimeState(){return timeState;}

    void processMessage(Message msg){
        timeState[msg.sender]++;
        std::cout << "Process["<<id+1<<"]: Processed Messgage from "<< msg.sender+1 << ": " << msg.data << std::endl;
    }

    void broadcast(Message msg){
        for(int i = 0; i < n; i++){
            if(i!=id){
                processes[i].recieveMessage(msg);
            }
        }
    }

    void sendMessage(Message msg, unsigned int reciever){
        std::cout << "Process["<<id+1<<"]: Sending Messgage to "<< reciever+1 << std::endl;
        processes[reciever].recieveMessage(msg);
    }

    friend Message createMessage(std::string data, int parentId);
};

#endif // BSS_PROCESS_H_