#include <gtest/gtest.h>

//https://www.youtube.com/watch?v=J27HoZM_PTI
//For linux we might have to use xvfb or -platform offscreen

GTEST_API_ int main(int argc, char **argv) {
    printf("Running main() from %s\n", __FILE__);
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
