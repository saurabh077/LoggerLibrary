#include "SinkFactory.h"
#include <iostream>

std::shared_ptr<Sinker> SinkFactory::createSink(const std::string& sink_type,
    const std::unordered_map<std::string, std::string>& config){

    //before comparing the sink_type check if it empty and first convert it to lowercase
    if(sink_type.empty()){
        std::cout << "Sink type not specified" << std::endl;
        return nullptr;
    }
    //std::cout<<"Sink type:"<<sink_type<<std::endl;
    //convert the sink_type to lowercase
    std::string sink_type_lower = sink_type;
    std::transform(sink_type_lower.begin(), sink_type_lower.end(), sink_type_lower.begin(), ::tolower);
    if(sink_type_lower == "file"){
        auto it = config.find("file_location");
        if(it == config.end()){
            std::cout << "File location not specified" << std::endl;
            return nullptr;
        }
        return FileSink::getInstance(it->second);
    } else if (sink_type_lower == "db"){
        auto hostIt = config.find("dbhost");
        auto portIt = config.find("dbport");
        //std::cout<<"Host:"<<hostIt->second<<" Port:"<<portIt->second<<std::endl;
        if(hostIt == config.end() || portIt == config.end()){
            std::cerr << "DB host not specified" << std::endl;
            return nullptr;
        }
        return DBSink::getInstance(hostIt->second, portIt->second);
    } else if (sink_type_lower == "console"){
        return ConsoleSink::getInstance();
    }
    return nullptr;
}