#pragma once
#include "TimeFormat.h"

class TimeYMDFormat: public TimeFormat {
    public:
    std::string getFormattedTime() override;
    ~TimeYMDFormat() = default;
};