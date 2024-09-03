#ifndef LAB_11_CHAT_CHATMESSAGE_H
#define LAB_11_CHAT_CHATMESSAGE_H

#include <string>
#include "User.h"

using namespace std;
class ChatMessage {
public:
    ChatMessage(User  f, User  t, string txt, bool r = false);

    [[nodiscard]] User getFrom() const;
    [[nodiscard]] User getTo() const;
    [[nodiscard]] string getText() const;

    [[nodiscard]] bool isRead() const;
    void setAsRead();

    bool operator==(const ChatMessage& right) const;

protected:
    User from;
    User to;
    string text;
    bool read;
};

#endif
