#ifndef LAB_11_CHAT_CHATREGISTER_H
#define LAB_11_CHAT_CHATREGISTER_H

#include <list>
#include <map>
#include "Chat.h"

using namespace std;
class ChatRegister {
public:
    void addChat(const User& user1, const User& user2);
    void removeChat(const User& user1, const User& user2);
    Chat& getChat(const User& user1, const User& user2);

    map<pair<string, string>, Chat> getChats() const;

    // visual methods
    void printChats() const;

protected:
    map<pair<string, string>, Chat> chats = {};
};

#endif
