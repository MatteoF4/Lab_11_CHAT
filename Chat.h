#ifndef LAB_11_CHAT_CHAT_H
#define LAB_11_CHAT_CHAT_H

#include <vector>
#include <iostream>
#include "User.h"
#include "ChatMessage.h"

using namespace std;
class Chat {
public:
    Chat(const User& a, const User& b);

    User& getUserA();
    User& getUserB();
    vector<ChatMessage> getMessages() const;

    void receiveMessage(const ChatMessage& msg);

    // visual methods
    void printUsers() const;
    void printMessages() const;

protected:
    User userA;
    User userB;
    vector<ChatMessage> messages = {};
};


#endif
