#ifndef LAB_11_CHAT_CHAT_H
#define LAB_11_CHAT_CHAT_H

#include <vector>
#include "User.h"
#include "ChatMessage.h"

using namespace std;
class Chat {
public:
    Chat(User* a, User* b);

    vector<User*> getUsers() const;
    vector<ChatMessage> getMessages() const;
    void receiveMessage(const ChatMessage& msg);

protected:
    vector<User*> users;
    vector<ChatMessage> messages = {};
};


#endif
