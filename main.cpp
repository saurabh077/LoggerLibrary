#include "Message.h"
#include "FileSink.h"
#include "LoggerLibrary.h"
#include <memory>


int main(){
    auto log = Logger::getInstance();
    log->warn("Somemessage by Saurabh");
    return 0;
}   