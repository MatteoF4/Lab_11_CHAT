#include <gtest/gtest.h>

#include "../User.h"

TEST(User, Constructor) {
    User u("Giorgio", "3671119852");

    EXPECT_EQ(u.getName(), "Giorgio");
    EXPECT_EQ(u.getNumber(), "3671119852");
}
