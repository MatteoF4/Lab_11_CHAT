#include "Chat.h"

#include <utility>

Chat::Chat(User  a, User  b) : userA(std::move(a)), userB(std::move(b)) {}

User& Chat::getUserA() {
    return userA;
}
User& Chat::getUserB() {
    return userB;
}
vector<Message> Chat::getMessages() const {
    return messages;
}
vector<Message> Chat::getUnreadMessages() const {
    vector<Message> unreadMessages = {};
    for(auto& msg : messages) {
        if (!msg.isRead())
            unreadMessages.push_back(msg);
    }
    return unreadMessages;
}


void Chat::sendMessage(const string &text, const User& from) {
    if(!(from == this->userA or from == this->userB))
        throw invalid_argument("can't send a message from a User which is not part of the Chat");
    User to = (from.getNumber() == userA.getNumber()) ?
            userB : userA;
    Message msg(from, to, text);
    messages.push_back(msg);
}

void Chat::readMessage(const Message &msg) {
    for(auto& m : messages) {
        if(m == msg) // making sure the message is actually in the chat before reading it
            m.setAsRead();
    }
}

void Chat::readAllMessages() {
    for(const auto& el : getUnreadMessages())
        this->readMessage(el);
}

bool Chat::operator==(const Chat &right) const {
    bool result = false;
    if(this->userA == right.userA
        and this->userB == right.userB
        and this->messages == right.messages)
        result = true;
    return result;
}
