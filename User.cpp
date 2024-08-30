#include "User.h"

#include <utility>

User::User(string  n) : name(std::move(n)) {}

string User::getName() const {
    return name;
}

void User::sendMessage(const string& text, Chat &chat) const {
    string receiver = chat.getUsers()[0] == this->getName() ?
            chat.getUsers()[1] : chat.getUsers()[0];
    ChatMessage msg(this->getName(), receiver, text);
    chat.receiveMessage(msg);
}
