#include "FileSink.h"
#include "DBSink.h"
#include "ConsoleSink.h"
#include <memory>
#include <unordered_map>
class SinkFactory {

    public:
    static std::shared_ptr<Sinker> createSink(const std::string& sink_type,
        const std::unordered_map<std::string, std::string>& config);
};