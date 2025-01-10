cmake_minimum_required(VERSION 3.10)

#Name of project
project(CipherLib)

# Compilator settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(include)

# Dodaj plik źródłowy
add_executable(CipherLib src/main.cpp)