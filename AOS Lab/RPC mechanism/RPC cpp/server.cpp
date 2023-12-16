#include "serverSocket.h"

#include <chrono>
#include <fstream>

std::string getTime(){
    std::time_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    char buf[80];
    std::strftime(buf, sizeof(buf), "%F %r", std::localtime(&now));
    std::cout << std::string(buf) << std::endl;
    return std::string(buf);
}

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
    ServerSocket socket(port);
    bool working = true;
    while(working){
        socket.accept();
        socket.send(("Hello, World!\nServer time: " + getTime()).c_str());
        while(true){
            std::string str = socket.recieve(255);
            std::string result;
            if(!strcmp(str.c_str(),"ADD")){
                socket.send("Enter 1st number");
                str = socket.recieve(255).c_str();
                int a = atoi(str.c_str());
                socket.send("Enter 2nd number");
                result = str + " + ";
                str = socket.recieve(255).c_str();
                result += str;
                int b = atoi(str.c_str());
                std::cout << "Asked to add " << a << " and " << b << std::endl;
                result +=  " = " + std::to_string(a+b);
            }
            else if(!strcmp(str.c_str(),"TIME")){
                std::cout << "Asked for server time" << std::endl;
                result = getTime();
            }
            else if(!strcmp(str.c_str(),"CLOSE")){
                std::cout << "Asked to close server. Requesting authorization" << std::endl;
                socket.send("Enter Password");
                str = socket.recieve(255);
                if(!strcmp(str.c_str(),"SECRET")){
                    result = "Closing";
                    socket.send("Closing");
                    working = false;
                    break;
                }
                else{
                    result = "Incorrect Password";
                }
            }
            else if(!strcmp(str.c_str(),"DISCONNECT")){
                result = "Disconnecting";
                socket.send("Disconnecting");
                break;
            }
            else if(!strcmp(str.c_str(),"FILE")){
                socket.send("Enter Filename");
                std::string filename = socket.recieve(255);
                str = socket.recieve(1024*1024*10); // 10 MB Max Size
                std::ofstream fs("serverFiles/"+filename);
                fs << str.c_str();
                result = "Transfer Done";
                socket.send(result);
                break;
            }
            else{
                std::cout << "Unknown Procedure " << str << std::endl;
                result = "Unknown procedure " + str; 
            }
            socket.send(result);
        }
        socket.disconnect();
    }
}