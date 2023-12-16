#ifndef BSS_MESSAGE_H_
#define BSS_MESSAGE_H_

#include <string>
#include <vector>

class Message{
private:
    Message(std::string data, std::vector<unsigned int> timeStamp, unsigned int sender): data(data), timeStamp(timeStamp.begin(), timeStamp.end()), sender(sender){}

public:
    std::string data;
    std::vector<unsigned int> timeStamp;
    unsigned int sender;

    friend Message createMessage(std::string data, int parentId);
};


#endif // BSS_MESSAGE_H_