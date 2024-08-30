#include <iostream>

#include "UserManager.h"

int main() {
    UserManager userMg1("Matteo");
    UserManager userMg2("Paolo");

    Chat chat1(userMg1.getActiveUser(), userMg2.getActiveUser());

    userMg1.openChat(&chat1);

    userMg1.send("Ciao");

    return 0;
}
