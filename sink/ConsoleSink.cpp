#include "ConsoleSink.h"

bool ConsoleSink::pushLogs(std::unique_ptr<Message>& message){
    std::cout<<"Message from Console Sink:"<<std::endl;
    message->print();
    return true;
}

std::shared_ptr<ConsoleSink> ConsoleSink::unique_console_sink_ = nullptr; 
std::shared_ptr<ConsoleSink> ConsoleSink::getInstance() {
    if (unique_console_sink_ == nullptr) {
        unique_console_sink_ = std::shared_ptr<ConsoleSink>(new ConsoleSink());
    }
    return unique_console_sink_;
}