#include <gtest/gtest.h>

#include "../Chat.h"

TEST(Chat, sendMessage) {
    User a("Paolo", "123");
    User b("Poldo", "321");

    Chat c(a, b);

    c.sendMessage("ciao!", a);

    ASSERT_EQ(c.getMessages().size(), 1);

    ChatMessage msg = c.getMessages()[0];

    EXPECT_EQ(msg.getText(), "ciao!");
    EXPECT_EQ(msg.getFrom().getNumber(), "123");
    EXPECT_EQ(msg.getTo().getNumber(), "321");
}
