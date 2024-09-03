#include <stdexcept>
#include <utility>
#include "ChatMessage.h"

ChatMessage::ChatMessage(User f, User t, std::string txt, bool r) : from(std::move(f)),
    to(std::move(t)), text(std::move(txt)), read (r) {}

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
    else
        throw logic_error("the message was already read");
}

bool ChatMessage::operator==(const ChatMessage &right) const {
    bool result = false;
    if(this->getFrom() == right.getFrom()
        and this->getTo() == right.getTo()
        and this->getText() == right.getText())
        result = true;
    return result;
}
