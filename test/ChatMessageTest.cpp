#include <gtest/gtest.h>

#include "../ChatMessage.h"

TEST(ChatMessage, Constructor) {
    User f("Gianni", "123");
    User t("Giulio", "321");

    ChatMessage c(f, t, "prova a a");

    EXPECT_EQ(c.getText(), "prova a a");
}
