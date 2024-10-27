cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 20)
project(LoggerLibraryProject)

# Add the timeformat subdirectory
add_subdirectory(message)
add_subdirectory(timeformat)
add_subdirectory(sink)


# Create a library for the LoggerLibrary
add_library(LoggerLibrary
    LoggerLibrary.cpp
)

# Specify include directories for the LoggerLibrary
target_include_directories(LoggerLibrary
    PUBLIC
    ${PROJECT_SOURCE_DIR}/timeformat
    ${PROJECT_SOURCE_DIR}/sink
    ${PROJECT_SOURCE_DIR}/message
)

# Link the timeformat library to LoggerLibrary
target_link_libraries(LoggerLibrary
    PUBLIC
    timeformat
    sink
    message
)

# Add the executable for the LoggerLibrary
add_executable(LoggerLibraryExecutable
    main.cpp
)

# Link the LoggerLibrary to the executable
target_link_libraries(LoggerLibraryExecutable
    PUBLIC
    LoggerLibrary
)