#include "Message.h"




void Message::print(){
    std::cout<<content_<<std::endl;
    // std::cout<<"LogLevel: "<<logLevel_<<std::endl;
    // std::cout<<"Namespace: "<<namespace_<<std::endl;
    //sink_->pushLogs();
}
MessageLevel Message::getMessageLevel(){
    return level_;
}