#include "TimeDMYFormat.h"

 std::string TimeDMYFormat::getFormattedTime() {
        std::time_t current_time = getCurrentTime();
        
        std::tm now_tm = *std::localtime(&current_time);
        std::ostringstream oss;
        //oss << std::put_time(&now_tm, "%Y-%m-%d:%H:%M:%S");
        oss << std::put_time(&now_tm, "%d-%m-%Y:%H:%M:%S");
        return oss.str();
    }