#pragma once
#include "TimeDMYFormat.h"
#include "TimeYMDFormat.h"
#include <memory>

class TimeFormatFactory {
    public:
    static std::unique_ptr<TimeFormat> getTimeFormat(std::string format);
};