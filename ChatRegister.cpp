#include "ChatRegister.h"


void ChatRegister::addChat(const User &userA, const User &userB) {
    auto key = createKey(userA.getNumber(), userB.getNumber());
    if(chats.find(key) == chats.end())
        chats.insert({key, Chat(userA, userB)});
    else
        throw logic_error("can't add a chat that already exists");
}

void ChatRegister::removeChat(const User &userA, const User &userB) {
    auto key = createKey(userA.getNumber(), userB.getNumber());
    if(!(chats.find(key) == chats.end()))
        chats.erase(key);
    else
        throw out_of_range("can't remove non-existing chat");
}

Chat& ChatRegister::getChat(const User &userA, const User &userB) {
    auto key = createKey(userA.getNumber(), userB.getNumber());
    if(chats.find(key) != chats.end())
        return chats.at(key);
    else
        throw out_of_range("can't retrieve non-existing chat");
}

map<pair<string, string>, Chat> ChatRegister::getChats() const {
    return chats;
}


/* 
 * orders the users' numbers in alphanumerical order, making
 * the access to the chats possible even with reversed users
 * as inputs
*/
pair<string, string> ChatRegister::createKey(const string& a, const string& b) {
    if(a > b)
        return make_pair(a, b);
    else
        return make_pair(b, a);
}

