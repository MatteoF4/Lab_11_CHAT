#include "ChatMessage.h"

ChatMessage::ChatMessage(const User &f, const User &t, std::string txt) : from(f),
    to(t), text(std::move(txt)) {}

User ChatMessage::getFrom() const {
    return from;
}
User ChatMessage::getTo() const {
    return to;
}
string ChatMessage::getText() const {
    return text;
}

bool ChatMessage::isRead() const {
    return read;
}
void ChatMessage::setAsRead() {
    if(!read)
        read = true;
    else; // cerr << "the message was already read" << endl;
}
