#include "clientSocket.h"

#include <cstring>
#include <fstream>

int main(int argc, char** argv){
    int port = 8080;
    if(argc>1){
        try{
            port = atoi(argv[1]);
        }
        catch(...){
            port = 8080;
        }
    }
    ClientSocket socket;
    socket.connect("127.0.0.1",port);
    std::string str = socket.recieve(255);
    std::cout << str << std::endl;
    while(true){
        std::cout << "Client: ";
        std::cout.flush();
        std::cin.getline(&str[0],255);
        socket.send(str.c_str());
        str = socket.recieve(255);
        std::cout << "Server: " << str.c_str() << std::endl;
        if(!strcmp(str.c_str(),"")){
            continue;
        }
        if(!strcmp(str.c_str(),"Enter Filename")){
            std::cout << "Client: ";
            std::cin.getline(&str[0],255);
            socket.send(str.c_str());
            std::ifstream fs("clientFiles/"+str);
            std::string data;
            data.resize(1024*1024*10);
            fs.read(&data[0],1024*1024*10);
            socket.send(data);
            std::cout << "Server: " << socket.recieve(255).c_str() << std::endl;
        }
        if(!strcmp(str.c_str(),"Closing")){
            break;
        }
        if(!strcmp(str.c_str(),"Disconnecting")){
            break;
        }
        
    }
}