#include "ChatRegister.h"


void ChatRegister::addChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    if(chats.find(key) == chats.end())
        chats.at(key) = Chat(user1, user2);
    else; // cerr << "chat already exists" << endl;
}

void ChatRegister::removeChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    if(!(chats.find(key) == chats.end()))
        chats.erase(key);
    else; // cerr << "the chat doesn't exist, it can't be deleted" << endl;
}

Chat& ChatRegister::getChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    return chats.at(key);
}

void ChatRegister::printChats() const {
    for(const auto& c : chats) {
        cout << c.first.first << " - " << c.first.second << endl;
    }
}
