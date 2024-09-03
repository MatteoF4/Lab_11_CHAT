#include "ChatRegister.h"


void ChatRegister::addChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    if(chats.find(key) == chats.end())
        chats.insert({key, Chat(user1, user2)});
    else
        throw logic_error("can't add a chat that already exists");
}

void ChatRegister::removeChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    if(!(chats.find(key) == chats.end()))
        chats.erase(key);
    else
        throw out_of_range("can't remove non existing chat");
}

Chat& ChatRegister::getChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    if(chats.find(key) != chats.end())
        return chats.at(key);
    else
        throw out_of_range("can't retrieve non existing chat");
}

map<pair<string, string>, Chat> ChatRegister::getChats() const {
    return chats;
}

