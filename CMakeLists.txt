cmake_minimum_required(VERSION 3.28)
project(Lab_11_CHAT)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_11_CHAT main.cpp
        User.cpp
        User.h
        Chat.cpp
        Chat.h
        ChatMessage.h
        ChatRegister.h
        ChatMessage.cpp
        ChatRegister.cpp)
