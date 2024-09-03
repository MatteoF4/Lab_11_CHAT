#include <gtest/gtest.h>

#include "../User.h"

TEST(User, Constructor) {
    User u("Alberto", "1");

    EXPECT_EQ(u.getName(), "Alberto");
    EXPECT_EQ(u.getNumber(), "1");
}

TEST(User, Setters) {
    User u("Bruno", "2");

    u.changeName("Alberto");
    EXPECT_EQ(u.getName(), "Alberto");

    u.changeNumber("1");
    EXPECT_EQ(u.getNumber(), "1");
}
