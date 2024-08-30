#ifndef LAB_11_CHAT_USER_H
#define LAB_11_CHAT_USER_H

#include <string>

using namespace std;
class User {
public:
    explicit User(string  n);

    string getName() const;
protected:
    string name;
};


#endif
