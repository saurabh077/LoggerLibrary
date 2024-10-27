cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 20)

# Add the adpodresponse library
add_library(message
    Message.cpp
    MessageLevel.cpp
)

# add_executable(main
#     SinkMain.cpp
# )
# target_link_libraries(main 
#     PUBLIC
#     sink
# )
