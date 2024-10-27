#include <fstream>
#include <unordered_map>
#include "LoggerLibrary.h"
#include <sstream>
#include <unistd.h> // For getcwd
#include "TimeFormatFactory.h"
#include "SinkFactory.h"

//change to logger

std::shared_ptr<Logger> Logger::unique_logger_ = nullptr;
bool Logger::configure(){

    std::ifstream file("config.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open config file" << std::endl;
        return false;
    }
    std::string line;
    std::string sink_type;
    std::unordered_map<std::string, std::string> config;
    while (std::getline(file, line)) {
       // std::cout<<"line::"<<line<<std::endl;
        std::istringstream stream(line);
        std::string key, value;
        
        //Split the line at the first colon
        //ts_format:dd:mm:yyyy hh:mm:ss
        //log_level:ERROR
        //sink_type:DB
        //dbhost:<ip address>
        // dbport:<db port>
        if (std::getline(stream, key, ':') && std::getline(stream, value)) {
            // std::cout<<"Key: "<<key
            // <<" Value: "<<value<<std::endl;
            config[key] = value;
            if(key == "ts_format"){
                time_format_ = TimeFormatFactory::getTimeFormat(value); //can be singleton
            } else if (key == "log_level"){
                log_level_ = MessageLevelFactory::setMessageLevel(value);
                if(log_level_ >= MAX_MESSAGE_LEVEL || log_level_ <= 0){
                    std::cerr << "Invalid log level" << std::endl;
                    return false;
                }
            } else if (key == "sink_type"){
                sink_type = value;
            }
        }
    }
    if(!sink_type.empty()){
        auto sink = SinkFactory::createSink(sink_type, config);
        if(sink == nullptr){
            std::cerr << "Sink not created" << std::endl;
            return false;
        }
        sink_map_[log_level_] = std::move(sink);
        //std::cout<<"Sink set successfully"<<std::endl;
        return true;
    }
    return false;
}

std::string Logger::enrichMessage(std::string content){
    //get time format and append the message to that time and return
    //std::cout << "Enriched Message" << std::endl;

    if(time_format_ == nullptr){
        std::cerr << "Time format not set" << std::endl;
        return "";
    }
    std::string time = time_format_->getFormattedTime();
    std::ostringstream oss;
    oss << MessageLevelFactory::getMessageLevel(log_level_);
    oss << " [" << time << "] " << content; 
    return oss.str();
}

int Logger::enrichAndSend(std::unique_ptr<Message>& message){
    if(message == nullptr)
        return -1;
    std::string enriched_message = enrichMessage(message->getContent());
    if(enriched_message == ""){
        return -1;
    }
    //std::cout << enriched_message << std::endl;
    message->setContent(enriched_message);
    auto sink = sink_map_[message->getMessageLevel()];
    if(sink == nullptr) {
        std::cerr << "Sink not set" << std::endl;
        return -1;
    }

   sink->pushLogs(message);
    return 0;
}

void Logger::log(std::string content, MessageLevel message_level){
    auto message = std::make_unique<Message>(content, message_level);
    int retval = enrichAndSend(message);
    if(retval == -1){
        std::cerr<<"Failed to log info:"<<content<<std::endl;
    }
}

void Logger::debug(std::string content){
    log(content, MessageLevel::DEBUG);
    return ;
}
void Logger::info(std::string content){
    log(content, MessageLevel::INFO);
    return ;
}
void Logger::warn(std::string content){
    log(content, MessageLevel::WARN);
    return ;
}
void Logger::error(std::string content){
    log(content, MessageLevel::ERROR);
    return ;
}
void Logger::fatal(std::string content){
    log(content, MessageLevel::FATAL);
    return ;
}