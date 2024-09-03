#include "Chat.h"

#include <utility>

Chat::Chat(User  a, User  b) : userA(std::move(a)), userB(std::move(b)) {}

User& Chat::getUserA() {
    return userA;
}
User& Chat::getUserB() {
    return userB;
}
vector<ChatMessage> Chat::getMessages() const {
    return messages;
}

void Chat::sendMessage(const string &text, const User& from) {
    User to = (from.getNumber() == userA.getNumber()) ?
            userB : userA;
    ChatMessage msg(from, to, text);
    messages.push_back(msg);
}

bool Chat::operator==(const Chat &right) const {
    bool result = false;
    if(this->userA == right.userA
        and this->userB == right.userB
        and this->messages == right.messages)
        result = true;
    return result;
}
