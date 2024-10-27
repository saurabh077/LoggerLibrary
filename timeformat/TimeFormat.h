#pragma once
#include <string>
class TimeFormat {
    std::string time_;
    protected:
    std::time_t getCurrentTime(){
        auto now = std::chrono::system_clock::now();
        std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
        return now_time_t;
    }
    public:
    virtual std::string getFormattedTime() = 0;
    virtual ~TimeFormat() = default;
};  