#include "User.h"

#include <utility>

User::User(string  n, int num) : name(std::move(n)), number(num) {}

string User::getName() const {
    return name;
}
int User::getNumber() const {
    return number;
}
void User::changeName(const string& n) {
    name = n;
}
void User::changeNumber(int num) {
    number = num;
}