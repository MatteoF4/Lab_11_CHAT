#ifndef LAB_11_CHAT_USER_H
#define LAB_11_CHAT_USER_H

#include <string>

using namespace std;
class User {
public:
    explicit User(string  n, int num);

    string getName() const;
    int getNumber() const;
    void changeName(const string& n);
    void changeNumber(int num);

protected:
    string name;
    int number;
};


#endif
