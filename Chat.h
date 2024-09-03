#ifndef LAB_11_CHAT_CHAT_H
#define LAB_11_CHAT_CHAT_H

#include <vector>
#include <iostream>
#include "User.h"
#include "ChatMessage.h"

using namespace std;
class Chat {
public:
    Chat(User  a, User  b);

    User& getUserA();
    User& getUserB();
    [[nodiscard]]
    vector<ChatMessage> getMessages() const;

    void sendMessage(const string& text, const User& from);

    bool operator==(const Chat& right) const;

protected:
    User userA;
    User userB;
    vector<ChatMessage> messages = {};
};


#endif
