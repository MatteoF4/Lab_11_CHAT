#include <iostream>
#include <memory>
#include "UserManager.h"

UserManager::UserManager(const string& username) {
    init(username);
}

void UserManager::init(const string& username) {
    activeUser = new User(username);
}

vector<Chat *> UserManager::getChats() {
    vector<Chat*> result = {};
    for(auto chat : chatRegister) {
        if(chat->getUsers()[0]->getName() == activeUser->getName() or
            chat->getUsers()[1]->getName() == activeUser->getName())
            result.push_back(chat);
    }
    return result;
}

void UserManager::openChat(Chat* target) {
    openedChat = target;
    if(openedChat->getUsers()[0]->getName() == activeUser->getName())
        activeReceiver = new User(*openedChat->getUsers()[1]);
    else
        activeReceiver = new User(*openedChat->getUsers()[0]);
}

void UserManager::send(const string &text) {
    ChatMessage msg(activeUser->getName(), activeReceiver->getName(), text);
    openedChat->receiveMessage(msg);
}

User* UserManager::getActiveUser() const {
    return activeUser;
}
void UserManager::setActiveUser(User* user) {
    activeUser = user;
}


