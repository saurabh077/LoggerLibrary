#include "TimeFormatFactory.h"

int main(){
    auto time = TimeFormatFactory::getTimeFormat("ddmmyyyy");
    std::cout<<time->getFormattedTime()<<std::endl;
    auto time2 = TimeFormatFactory::getTimeFormat("yymmdd");
    std::cout<<time2->getFormattedTime()<<std::endl;
    return 0;
}