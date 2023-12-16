#ifndef CLIENTSERVER_CLIENTSOCKET_H_
#define CLIENTSERVER_CLIENTSOCKET_H_

#include "socket.h"

class ClientSocket:public Socket{
public:

    void connect(std::string ip, int port){
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        server_address.sin_addr.s_addr = inet_addr(ip.c_str());
        if(::connect(sockfd, (sockaddr*)&server_address, sizeof(server_address))<0){
            throw std::runtime_error("ERROR: Unable to connect");
        }
        else{
            std::cout << "Connection to " << inet_ntoa(server_address.sin_addr) << ":" << ntohs(server_address.sin_port) << " Succeded" << std::endl;
        }
    }

    void send(std::string s){
        if(::write(sockfd, s.c_str(), s.size())<0){
            throw std::runtime_error("ERROR: Unable to write to socket");
        }
    }

    std::string recieve(int bufsize){
        std::string buffer;
        buffer.resize(bufsize);
        if(::read(sockfd, &buffer[0],bufsize)<0){
            throw std::runtime_error("ERROR: Unable to read from socket");
        };
        return buffer;
    }

};

#endif // CLIENTSERVER_CLIENTSOCKET_H_