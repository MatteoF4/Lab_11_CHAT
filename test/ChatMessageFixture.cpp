#include <gtest/gtest.h>

#include "../Message.h"

class ChatMessageFixture : public ::testing::Test {
protected:
    ChatMessageFixture() : f("Alberto", "1"),
    t("Bruno", "2"), c(f, t, "ciao") {}

    //void SetUp() override {}
    //void TearDown() override {}

    User f;
    User t;
    Message c;
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
    Message c1(f, t, "ciao");
    EXPECT_TRUE(c == c1);

    Message c2(f, t, "hello");
    EXPECT_FALSE(c == c2);

    Message c3(t, f, "ciao");
    EXPECT_FALSE(c == c3);
}
