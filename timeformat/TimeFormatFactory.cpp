#include "TimeFormatFactory.h"

std::unique_ptr<TimeFormat> TimeFormatFactory::getTimeFormat(std::string format){
    if(format == "ddmmyyyy"){
        return std::make_unique<TimeDMYFormat>();
    } else {
        return std::make_unique<TimeYMDFormat>();
    }
}