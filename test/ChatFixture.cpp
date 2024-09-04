#include <gtest/gtest.h>

#include "../Chat.h"

class ChatFixture : public ::testing::Test {
protected:
    ChatFixture() : a("Alberto", "1"),
                           b("Bruno", "2"),
                           d("Diana", "3"), c(a, b) {}

    //void SetUp() override {}
    //void TearDown() override {}

    User a;
    User b;
    User d;
    Chat c;
};

TEST_F(ChatFixture, Constructor) {
    ASSERT_EQ(c.getMessages().size(), 0);
    EXPECT_EQ(c.getUserA().getNumber(), "1");
    EXPECT_EQ(c.getUserB().getNumber(), "2");
}

TEST_F(ChatFixture, SendMessage) {
    c.sendMessage("ciao", a);

    ASSERT_EQ(c.getMessages().size(), 1);

    ChatMessage msg = c.getMessages()[0];

    EXPECT_EQ(msg.getText(), "ciao");
    EXPECT_EQ(msg.getFrom().getNumber(), "1");
    EXPECT_EQ(msg.getTo().getNumber(), "2");
}

TEST_F(ChatFixture, WrongUserSendsMessage) {
    EXPECT_THROW(c.sendMessage("ciao", d), invalid_argument);
}

TEST_F(ChatFixture, EqualConfront) {
    Chat c2(a, d);

    EXPECT_FALSE(c == c2);
    EXPECT_TRUE(c == c);
}

