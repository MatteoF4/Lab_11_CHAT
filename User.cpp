#include "User.h"

#include <utility>

User::User(string  n) : name(std::move(n)) {}

string User::getName() const {
    return name;
}
