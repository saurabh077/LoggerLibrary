#include "Sinker.h"
class ConsoleSink: public Sinker {
    static std::shared_ptr<ConsoleSink> unique_console_sink_;
    ConsoleSink(){}
    public:
    bool pushLogs(std::unique_ptr<Message>& message);    
    ~ConsoleSink() = default;
    static std::shared_ptr<ConsoleSink> getInstance() ;
};