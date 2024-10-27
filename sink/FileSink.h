#pragma once
#include <string>
#include <vector>
#include "Sinker.h"
#include <iostream>
#include <fstream>
#include <filesystem>

class FileSink: public Sinker {
    
    static std::shared_ptr<FileSink> unique_file_sink_;
    std::string file_location_;
    std::ofstream log_file_;
    size_t max_size_;
    FileSink(const std::string& file_location): file_location_(file_location) {
        openFile();
        max_size_ = 300;
    }

    void openFile();
    void rotateLog();
    std::string generateTimestampedLogFileName();
    void compressLogFile(const std::string& zip_file_path);
    public:
    static std::shared_ptr<FileSink> getInstance(const std::string& file_location);
    bool pushLogs(std::unique_ptr<Message>& message) override;
    ~FileSink() {
        if(log_file_.is_open()){
            log_file_.close();
        }
    }
};