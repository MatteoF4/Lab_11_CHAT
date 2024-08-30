#ifndef LAB_11_CHAT_CHATMESSAGE_H
#define LAB_11_CHAT_CHATMESSAGE_H

#include <string>
#include <utility>

using namespace std;
class ChatMessage {
public:
    ChatMessage(string f, string t, string txt) : from(std::move(f)),
        to(std::move(t)), text(std::move(txt)) {}

//protected:
    string from;
    string to;
    string text;
    bool read = false;
};

#endif
