#include "TimeYMDFormat.h"
#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <chrono>
std::string TimeYMDFormat::getFormattedTime() {
    std::time_t current_time = getCurrentTime();
    
    std::tm now_tm = *std::localtime(&current_time);
    std::ostringstream oss;
    oss << std::put_time(&now_tm, "%Y-%m-%d:%H:%M:%S");
    return oss.str();
}