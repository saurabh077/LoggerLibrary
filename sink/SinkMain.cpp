// #include <unordered_map>
// #include <string>
// #include "SinkFactory.h"

// int main() {
//     std::unordered_map<std::string, std::string> mp;
//     mp["dbhost"] = "file.txt";
//     mp["dbport"] = "file.txt";
//     std::unique_ptr<Sinker> sink = SinkFactory::createSink("db", mp);
//     std::unique_ptr<Message> ms = std::make_unique<Message>("Hello", MessageLevel::INFO, "SomeNamespace");
//     sink->pushLogs(ms);
//     return 0;
// }