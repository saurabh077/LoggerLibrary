cmake_minimum_required(VERSION 3.22.1)

set(CMAKE_CXX_STANDARD 20)

# Add the adpodresponse library
add_library(timeformat
    TimeDMYFormat.cpp
    TimeYMDFormat.cpp
    TimeFormatFactory.cpp   
)

# add_executable(main
#     TimeMain.cpp
# )
# target_link_libraries(main 
#     PUBLIC
#     timeformat
# )
