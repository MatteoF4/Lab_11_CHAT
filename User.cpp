#include "User.h"

#include <utility>

User::User(string  n, string num) : name(std::move(n)), number(std::move(num)) {}

string User::getName() const {
    return name;
}
string User::getNumber() const {
    return number;
}
void User::changeName(const string& n) {
    name = n;
}
void User::changeNumber(const string& num) {
    number = num;
}