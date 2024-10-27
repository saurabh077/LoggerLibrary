#pragma once
#include "Message.h"
#include <vector>
class Sinker {
    public:
    virtual bool pushLogs(std::unique_ptr<Message>& message) = 0;    
    virtual ~Sinker() = default;
};


/*




*/