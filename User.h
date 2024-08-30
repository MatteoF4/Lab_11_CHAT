#ifndef LAB_11_CHAT_USER_H
#define LAB_11_CHAT_USER_H

#include <string>
#include "ChatMessage.h"
#include "Chat.h"

using namespace std;
class User {
public:
    explicit User(string  n);

    string getName() const;

    void sendMessage(const string& text, Chat& chat) const;

protected:
    string name;
};


#endif
