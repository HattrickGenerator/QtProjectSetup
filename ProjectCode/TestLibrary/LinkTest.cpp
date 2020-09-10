#include <gtest/gtest.h>
#include "TestLibraryFunctionality.h"

TEST(TestBasicSetup, TestExampleFunctionLib) {
    EXPECT_EQ(true, LibraryTestFunction()) << "Wrong result of LibraryTestFunction";
}

