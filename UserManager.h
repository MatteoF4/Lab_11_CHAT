#ifndef LAB_11_CHAT_USERMANAGER_H
#define LAB_11_CHAT_USERMANAGER_H

#include <string>
#include <memory>
#include "User.h"
#include "Chat.h"

using namespace std;

static vector<Chat*> chatRegister = {};

class UserManager {
public:
    explicit UserManager(const string& username);

    vector<Chat*> getChats();
    void openChat(Chat* target);

    void send(const string& text);

    User* getActiveUser() const;
    void setActiveUser(User* user);

protected:
    User* activeUser;
    Chat* openedChat;
    User* activeReceiver;

    void init(const string& username);
};


#endif
