#include <memory>
#include "Message.h"
#include "TimeFormat.h"
#include <unordered_map>
#include "Sinker.h"

class Logger {

    static std::shared_ptr<Logger> unique_logger_;
    std::unique_ptr<TimeFormat> time_format_;
    int log_level_;
    //std::unique_ptr<Sinker> sink_;
    std::unordered_map<int, std::shared_ptr<Sinker>> sink_map_;
    std::string enrichMessage(std::string content);
    int enrichAndSend(std::unique_ptr<Message>& message);
    bool configure();
    bool routeMessageToSink();
    void log(std::string content, MessageLevel message_level);

    Logger(){
        if(!configure()){
            std::cerr<<"Failed to configure logger"<<std::endl;
        }
    }


    public:

    static std::shared_ptr<Logger> getInstance(){
        if(unique_logger_ == nullptr){
            unique_logger_ = std::shared_ptr<Logger>(new Logger());
            
        }
        return unique_logger_;
    }
    void debug(std::string content);
    void info(std::string content);
    void warn(std::string content);
    void error(std::string content);
    void fatal(std::string content);
};