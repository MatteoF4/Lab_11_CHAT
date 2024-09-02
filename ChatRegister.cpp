#include "ChatRegister.h"


void ChatRegister::addChat(const User &user1, const User &user2) {
    auto key = make_pair(user1.getNumber(), user2.getNumber());
    if(chats.find(key) == chats.end())
        chats.insert({key, Chat(user1, user2)});
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
    if(chats.find(key) != chats.end())
        return chats.at(key);
    else
        throw out_of_range("the chat does not exist");
}

map<pair<string, string>, Chat> ChatRegister::getChats() const {
    return chats;
}


void ChatRegister::printChats() const {
    for(const auto& c : chats) {
        cout << c.first.first << " - " << c.first.second << endl;
    }
}
