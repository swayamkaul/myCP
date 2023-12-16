#ifndef CLIENTSERVER_SOCKET_H_
#define CLIENTSERVER_SOCKET_H_

#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#include <cstring>
#include <iostream>
#include <string>
#include <exception>

class Socket{
protected:
    int sockfd=-1;
    sockaddr_in server_address;
public:
    Socket(){
        bzero(&server_address, sizeof(server_address));
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
    }

    void send(std::string s);

    ~Socket(){
        shutdown(sockfd, SHUT_RDWR);
        ::close(sockfd);
        sockfd = -1;
    }    
};

#endif // CLIENTSERVER_SOCKET_H_