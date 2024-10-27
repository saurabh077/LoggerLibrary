#pragma once
#include <string>

enum MessageLevel {
    DEBUG = 0,
    INFO, 
    WARN,
    ERROR,
    FATAL,
    MAX_MESSAGE_LEVEL
};

class MessageLevelFactory {
    
    public:
    static std::string getMessageLevel(int level);
    static MessageLevel setMessageLevel(std::string level);

};