#include "Chat.h"

Chat::Chat(User *a, User *b) {
    users.push_back(a);
    users.push_back(b);
}

vector<User *> Chat::getUsers() const {
    return users;
}
vector<ChatMessage> Chat::getMessages() const {
    return messages;
}

void Chat::receiveMessage(const ChatMessage& msg) {
    messages.push_back(msg);
}
