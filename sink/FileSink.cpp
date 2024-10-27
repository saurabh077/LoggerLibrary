#include <iostream>
#include "FileSink.h"
#include <sstream>
#include <filesystem>
#include <zip.h>

std::shared_ptr<FileSink> FileSink::unique_file_sink_ = nullptr;


void FileSink::openFile(){
    log_file_.open(file_location_, std::ios::app);
    if (!log_file_.is_open()) {
        throw std::runtime_error("Unable to open log file");
    }
}

bool FileSink::pushLogs(std::unique_ptr<Message>& message){

    if(log_file_.tellp() >= max_size_){
        rotateLog();
    }
    log_file_ << message->getContent() << std::endl;
    //std::cout<<"Pushed Logs to FileSink:"<<file_location_ << " "<< std::endl;
    return true;
}

std::shared_ptr<FileSink> FileSink::getInstance(const std::string& file_location) {
    if(unique_file_sink_ == nullptr){
        unique_file_sink_ = std::shared_ptr<FileSink>(new FileSink(file_location));
    }
    return unique_file_sink_;
}

void FileSink::rotateLog() {
    log_file_.close();
    std::string compressed_log_file_name = generateTimestampedLogFileName() + ".zip";
    compressLogFile(compressed_log_file_name);
    std::filesystem::remove(file_location_); // Optionally remove the original log file
    openFile();

}

std::string FileSink::generateTimestampedLogFileName() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm tm = *std::localtime(&t);

    std::ostringstream oss;
    oss << file_location_;
    oss << std::put_time(&tm, "_%Y-%m-%d_%H-%M-%S.log");
    return oss.str();
}

void FileSink::compressLogFile(const std::string& zip_file_path) {
    // Create a new zip archive
    zip_t *zip = zip_open(zip_file_path.c_str(), ZIP_CREATE | ZIP_EXCL, nullptr);
    if (!zip) {
            throw std::runtime_error("Unable to create zip file");
    }

    // Add the log file to the zip archive
    zip_source_t *source = zip_source_file(zip, file_location_.c_str(), 0, 0);
    if (!source) {
            zip_close(zip);
            throw std::runtime_error("Unable to add file to zip archive");
    }

    // Add the source to the zip archive
    if (zip_file_add(zip, std::filesystem::path(file_location_).filename().c_str(), source, ZIP_FL_OVERWRITE) < 0) {
            zip_source_free(source);
            zip_close(zip);
            throw std::runtime_error("Failed to add file to zip archive");
    }

    // Finalize the zip archive
    if (zip_close(zip) < 0) {
            throw std::runtime_error("Failed to close zip archive");
    }
}

// int main(){
//     Sinker* sink = new FileSink();
//     sink->pushLogs();
//     return 0;
// }