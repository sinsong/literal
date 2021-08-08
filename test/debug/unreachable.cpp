#include <gtest/gtest.h>

#include "literal/debug.h"

TEST(UnreachableDeathTest, DebugTest)
{
    ASSERT_DEATH({
        literal_unreachable("unreachable test");
    }, ".*UNREACHABLE executed.*");
}