#include "Chat.h"

Chat::Chat(const User& a, const User& b) : userA(a), userB(b) {}

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

void Chat::printUsers() const {
    cout << userA.getName() << " - " << userB.getName() << endl;
}
void Chat::printMessages() const {
    for(auto& m : messages) {
        cout << endl << m.getFrom().getName() << ": " << m.getText() << endl;
    }
}
