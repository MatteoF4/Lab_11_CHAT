#include <gtest/gtest.h>

#include "../ChatRegister.h"

class ChatRegisterFixture : public ::testing::Test {
protected:
    ChatRegisterFixture() : a(User("Alberto", "1")),
        b(User("Bruno", "2")), c(User("Carlo", "3")) {}

    void SetUp() override {
        cr.addChat(a, b);
        cr.addChat(a, c);
    }

    // void TearDown() override {}

    User a;
    User b;
    User c;
    ChatRegister cr;
};

TEST_F(ChatRegisterFixture, AddChat) {
    EXPECT_NO_THROW(cr.getChat(a, b));
    EXPECT_NO_THROW(cr.getChat(a, c));

    EXPECT_EQ(cr.getChats().size(), 2);
}

TEST_F(ChatRegisterFixture, GetNonExistingChat) {
    EXPECT_THROW(cr.getChat(b, c), out_of_range);
    EXPECT_THROW(cr.getChat(c, b), out_of_range);
}

TEST_F(ChatRegisterFixture, RemoveChat) {
    cr.removeChat(a, b);
    EXPECT_THROW(cr.getChat(a, b), out_of_range);
}

TEST_F(ChatRegisterFixture, RemoveNonExistingChat) {
    EXPECT_THROW(cr.removeChat(b, c), logic_error);
}

TEST_F(ChatRegisterFixture, ReverseGetChat) {
    EXPECT_NO_THROW(cr.getChat(a, b));
    EXPECT_NO_THROW(cr.getChat(b, a));

    EXPECT_NO_THROW(cr.getChat(a, c));
    EXPECT_NO_THROW(cr.getChat(c, a));
}
