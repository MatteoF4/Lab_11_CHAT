cmake_minimum_required(VERSION 3.28)
project(Lab_11_CHAT)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(test)

add_executable(${CMAKE_PROJECT_NAME} main.cpp)

set(SOURCE_FILES
        User.cpp
        User.h
        Chat.cpp
        Chat.h
        Message.h
        ChatRegister.h
        Message.cpp
        ChatRegister.cpp)

add_library(${CMAKE_PROJECT_NAME}_lib ${SOURCE_FILES})

target_link_libraries(${CMAKE_PROJECT_NAME} ${CMAKE_PROJECT_NAME}_lib)
