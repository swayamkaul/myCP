#ifndef CLIENTSERVER_SERVERSOCKET_H_
#define CLIENTSERVER_SERVERSOCKET_H_

#include "socket.h"

class ServerSocket:public Socket{
    int client_sockfd=-1;
    sockaddr_in client_address;

public:
    ServerSocket(int port, int backlogSize=5){
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(port);
        server_address.sin_addr.s_addr = INADDR_ANY;
        if(bind(sockfd, (sockaddr*) &server_address, sizeof(server_address))<0){
            throw std::runtime_error("ERROR: Unable to bind socket");
        }
        listen(sockfd,backlogSize);
        std::cout << "Server listening at port " << port << std::endl;
    }

    void accept(){
        socklen_t cli_len = sizeof(client_address);
        client_sockfd = ::accept(sockfd, (sockaddr*)&client_address,&cli_len);
        if(client_sockfd<0){
            throw std::runtime_error("ERROR: Unable to accept");
        };
        std::cout << "Recieved connection from " << inet_ntoa(client_address.sin_addr) << ":" << ntohs(client_address.sin_port) << std::endl;
    }

    void send(std::string s){
        if(::write(client_sockfd, s.c_str(), s.size())<0){
            throw std::runtime_error("ERROR: Unable to write to socket");
        }
    }

    std::string recieve(int bufsize){
        std::string buffer;
        buffer.resize(bufsize);
        if(::read(client_sockfd, &buffer[0],bufsize)<0){
            throw std::runtime_error("ERROR: Unable to read from socket");
        };
        return buffer;
    }

    void disconnect(){
        if(shutdown(client_sockfd, SHUT_RDWR)<0){
            throw std::runtime_error("ERROR: Unable to shutdown connection");
        }
        ::close(client_sockfd);
        client_sockfd=-1;
        std::cout << "Connection to " << inet_ntoa(client_address.sin_addr) << ":" << ntohs(client_address.sin_port) << " closed." << std::endl;
        bzero(&client_address, sizeof(client_address));
    }

    ~ServerSocket(){
        shutdown(client_sockfd, SHUT_RDWR);
        ::close(client_sockfd);
        client_sockfd=-1;
    }
};

#endif // CLIENTSERVER_SERVERSOCKET_H_