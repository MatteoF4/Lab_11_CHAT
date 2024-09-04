#include <stdexcept>
#include <utility>
#include "Message.h"

Message::Message(User f, User t, std::string txt, bool r) : from(std::move(f)),
                                                            to(std::move(t)), text(std::move(txt)), read (r) {}

User Message::getFrom() const {
    return from;
}
User Message::getTo() const {
    return to;
}
string Message::getText() const {
    return text;
}

bool Message::isRead() const {
    return read;
}
void Message::setAsRead() {
    if(!read)
        read = true;
    else
        throw logic_error("the message was already read");
}

bool Message::operator==(const Message &right) const {
    bool result = false;
    if(this->getFrom() == right.getFrom()
        and this->getTo() == right.getTo()
        and this->getText() == right.getText()
        and this->read == right.read)
        result = true;
    return result;
}
