
project(TestCase)

set(srcFiles
TestLib.cpp
LinkTest.cpp
)

add_executable(TestCase ${srcFiles})

target_link_libraries(TestCase gtest gtest_main ${libProject} )
