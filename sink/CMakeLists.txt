cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 20)

# Add the adpodresponse library
add_library(sink
    DBSink.cpp
    FileSink.cpp
    SinkFactory.cpp
    ConsoleSink.cpp
)

target_link_libraries(sink
    PUBLIC
    -L/opt/homebrew/lib/
    -lzip
)

target_include_directories(sink
    PUBLIC
    ${PROJECT_SOURCE_DIR}/message
    /opt/homebrew/include/
)

# add_executable(main
#     SinkMain.cpp
# )
# target_link_libraries(main 
#     PUBLIC
#     sink
#     message
# )
