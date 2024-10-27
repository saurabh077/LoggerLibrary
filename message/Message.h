#pragma once
#include <iostream>
#include <string>
//#include "Sinker.h"
#include "MessageLevel.h"

class Message {
    std::string content_;
    MessageLevel level_;
    std::string namespace_;
    public:

    Message(std::string content, MessageLevel logLevel, std::string nm) {
        content_ = content;
        level_ = logLevel;
        namespace_ = nm;
    }
    Message(std::string content, MessageLevel logLevel) {
        content_ = content;
        level_ = logLevel;
    }
    void print();
    ~Message() = default;
    std::string getContent() { return content_; }
    void setContent(std::string content) { content_ = content; }
    MessageLevel getMessageLevel();
};