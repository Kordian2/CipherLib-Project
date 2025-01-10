cmake_minimum_required(VERSION 3.10)

# Name of project
project(CipherLib)

# Compiler settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

# Add source file
add_executable(CipherLib src/main.cpp)

# Custom target to simplify build and run process
add_custom_target(run
    COMMAND ${CMAKE_COMMAND} --build ${CMAKE_BINARY_DIR} --verbose
    COMMAND ${CMAKE_BINARY_DIR}/CipherLib.exe
    DEPENDS CipherLib
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)