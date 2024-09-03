#include <gtest/gtest.h>

#include "../ChatMessage.h"

class ChatMessageFixture : public ::testing::Test {
protected:
    ChatMessageFixture() : f("Alberto", "1"),
    t("Bruno", "2"), c(f, t, "ciao") {}

    //void SetUp() override {}
    //void TearDown() override {}

    User f;
    User t;
    ChatMessage c;
};

TEST_F(ChatMessageFixture, Constructor) {
    EXPECT_EQ(c.getText(), "ciao");
}

TEST_F(ChatMessageFixture, ReadMessage) {
    EXPECT_FALSE(c.isRead());
    c.setAsRead();
    EXPECT_TRUE(c.isRead());
}

TEST_F(ChatMessageFixture, ReadAlreadyReadMessage) {
    c.setAsRead();
    EXPECT_THROW(c.setAsRead(), logic_error);
}

TEST_F(ChatMessageFixture, EqualConfront) {
    ChatMessage c1(f, t, "ciao");
    EXPECT_TRUE(c == c1);

    ChatMessage c2(f, t, "hello");
    EXPECT_FALSE(c == c2);

    ChatMessage c3(t, f, "ciao");
    EXPECT_FALSE(c == c3);
}
