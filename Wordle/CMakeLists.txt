cmake_minimum_required(VERSION 3.21)
project(ASSIGN5 C)

set(CMAKE_C_STANDARD 17)

add_executable(ASSIGN5 src/main.c src/wordle.c inc/wordle.h)


#for dictionary api:
#include_directories(/usr/bin/curl/include/)

#set(CURL_LIBRARY "-lcurl")
#find_package(CURL REQUIRED)

#include_directories(${CURL_INCLUDE_DIR})
#target_link_libraries(ASSIGN5 ${CURL_LIBRARIES})