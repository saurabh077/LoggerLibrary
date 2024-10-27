#pragma once
#include <string>
#include "Sinker.h"
class DBSink: public Sinker {
    static std::shared_ptr<DBSink> unique_db_sink_;
    std::string db_host_;
    std::string db_port_;
    DBSink(const std::string& db_host, const std::string& db_port): db_host_(db_host), db_port_(db_port) {}
    public:
    static std::shared_ptr<DBSink> getInstance(const std::string& db_host, const std::string& db_port);

    bool pushLogs(std::unique_ptr<Message>& message) override;
    ~DBSink() = default;
};