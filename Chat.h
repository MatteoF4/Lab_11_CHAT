#ifndef LAB_11_CHAT_CHAT_H
#define LAB_11_CHAT_CHAT_H

#include <vector>
#include <iostream>
#include "User.h"
#include "Message.h"

using namespace std;
class Chat {
public:
    Chat(User  a, User  b);

    User& getUserA();
    User& getUserB();
    [[nodiscard]] vector<Message> getMessages() const;
    [[nodiscard]] vector<Message> getUnreadMessages() const;

    void sendMessage(const string& text, const User& from);
    void readMessage(const Message& msg);
    void readAllMessages();

    bool operator==(const Chat& right) const;

protected:
    User userA;
    User userB;
    vector<Message> messages = {};
};


#endif
