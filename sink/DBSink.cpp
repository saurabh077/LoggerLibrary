#include "DBSink.h"
#include <iostream>

std::shared_ptr<DBSink> DBSink::unique_db_sink_ = nullptr;
bool DBSink::pushLogs(std::unique_ptr<Message>& message){
    std::cout<<"Pushed Logs to DBSink: dbHost:"<<db_host_ <<" and port:" <<db_port_ <<std::endl;
    message->print();
    return true;
}

std::shared_ptr<DBSink> DBSink::getInstance(const std::string& db_host, const std::string& db_port) {
    if (unique_db_sink_ == nullptr) {
        unique_db_sink_ = std::shared_ptr<DBSink>(new DBSink(db_host, db_port));
    }
    return unique_db_sink_;
}