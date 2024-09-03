#include <gtest/gtest.h>

#include "../Chat.h"

TEST(Chat, Constructor) {
    User a("Alberto", "1");
    User b("Bruno", "2");

    Chat c(a, b);

    ASSERT_EQ(c.getMessages().size(), 0);
    EXPECT_EQ(c.getUserA().getNumber(), "1");
    EXPECT_EQ(c.getUserB().getNumber(), "2");
}

TEST(Chat, SendMessage) {
    User a("Alberto", "1");
    User b("Bruno", "2");

    Chat c(a, b);

    c.sendMessage("ciao", a);

    ASSERT_EQ(c.getMessages().size(), 1);

    ChatMessage msg = c.getMessages()[0];

    EXPECT_EQ(msg.getText(), "ciao");
    EXPECT_EQ(msg.getFrom().getNumber(), "1");
    EXPECT_EQ(msg.getTo().getNumber(), "2");
}

TEST(Chat, EqualConfront) {
    User a("Alberto", "1");
    User b("Bruno", "2");

    Chat c1(a, b);

    User d("Diana", "3");
    User e("Elena", "4");

    Chat c2(d, e);

    EXPECT_FALSE(c1 == c2);
    EXPECT_TRUE(c1 == c1);
}
