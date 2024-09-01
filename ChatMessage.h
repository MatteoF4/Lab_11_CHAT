#ifndef LAB_11_CHAT_CHATMESSAGE_H
#define LAB_11_CHAT_CHATMESSAGE_H

#include <string>
#include "User.h"

using namespace std;
class ChatMessage {
public:
    ChatMessage(const User& f, const User& t, string txt);

    User getFrom() const;
    User getTo() const;
    string getText() const;

    bool isRead() const;
    void setAsRead();
protected:
    User from;
    User to;
    string text;
    bool read = false;
};

#endif
