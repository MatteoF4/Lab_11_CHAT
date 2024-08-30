#ifndef LAB_11_CHAT_CHATREGISTER_H
#define LAB_11_CHAT_CHATREGISTER_H

#include <list>
#include "Chat.h"

using namespace std;
class ChatRegister {
public:
    list<Chat> getChats() {
        return chats;
    }
    void addChat(Chat& c) {
        chats.push_back(c);
    }

    // visual methods
    void printChats() {
        for(auto& c : chats) {
            cout << c.getUsers()[0]->getName() << " - " <<
                c.getUsers()[1]->getName() << endl;
        }
    }

protected:
    list<Chat> chats;
};


#endif
