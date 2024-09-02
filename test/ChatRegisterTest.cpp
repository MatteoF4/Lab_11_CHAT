#include <gtest/gtest.h>

#include "../ChatRegister.h"

TEST(ChatRegister, addChat) {
    ChatRegister cr;

    ASSERT_EQ(cr.getChats().size(), 0);

    User a("Alberto", "1");
    User b("Bruno", "2");

    cr.addChat(a, b);

    Chat chat = cr.getChat(a, b);

    EXPECT_EQ(chat.getUserA().getName(), "Alberto");
    EXPECT_EQ(chat.getUserB().getName(), "Bruno");

    EXPECT_TRUE(chat.getMessages().empty());
}

TEST(ChatRegistryTest, GetNonExistentChat) {
    User a("Alberto", "1");
    User b("Bruno", "2");

    ChatRegister cr;

    EXPECT_THROW(cr.getChat(a, b), out_of_range);
}

TEST(ChatRegistryTest, RemoveChat) {
    User a("Alberto", "1");
    User b("Bruno+", "2");

    ChatRegister cr;
    cr.addChat(a, b);

    EXPECT_NO_THROW(cr.getChat(a, b));

    cr.removeChat(a, b);

    EXPECT_THROW(cr.getChat(a, b), out_of_range);
}
