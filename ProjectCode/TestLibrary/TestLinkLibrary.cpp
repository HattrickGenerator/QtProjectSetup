#include <gtest/gtest.h>
#include "TestLibraryFunctionality.h"


TEST(LinkTest, TestLinkFunctionLib) {
    EXPECT_EQ(true, LibraryTestLinkFunction()) << "Should never fail. This function is only to have immediate view of linkage";
}

