#pragma once
#include "TimeFormat.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
class TimeDMYFormat: public TimeFormat {
    public:
    std::string getFormattedTime() override ;
    ~TimeDMYFormat() = default;
};