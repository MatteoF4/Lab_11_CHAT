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

TEST(User, EqualConfront){
    User u1("Alberto", "1");
    User u2("Alberto", "2");
    EXPECT_FALSE(u1 == u2);

    u2.changeNumber("1");
    EXPECT_TRUE(u1 == u2);

    u2.changeName("Bruno");
    EXPECT_FALSE(u1 == u2);
}
