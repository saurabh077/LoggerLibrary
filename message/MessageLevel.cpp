
#include "MessageLevel.h"

std::string MessageLevelFactory::getMessageLevel(int level){

    switch(level){
        case DEBUG:
            return "DEBUG";
        case INFO:
            return "INFO";
        case WARN:
            return "WARN";
        case ERROR:
            return "ERROR";
        case FATAL:
            return "FATAL";
        default:
            return "UNKNOWN";
    }
}

MessageLevel MessageLevelFactory::setMessageLevel(std::string level){
    
        if(level == "DEBUG"){
            return DEBUG;
        } else if(level == "INFO"){
            return INFO;
        } else if(level == "WARN"){
            return WARN;
        } else if(level == "ERROR"){
            return ERROR;
        } else if(level == "FATAL"){
            return FATAL;
        } else {
            return MAX_MESSAGE_LEVEL;
        }
}