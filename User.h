#ifndef LAB_11_CHAT_USER_H
#define LAB_11_CHAT_USER_H

#include <string>

using namespace std;
class User {
public:
    explicit User(string  n, string num);

    [[nodiscard]] string getName() const;
    [[nodiscard]] string getNumber() const;
    void changeName(const string& n);
    void changeNumber(const string& num);

    bool operator==(const User& right) const;

protected:
    string name;
    string number;
};


#endif
