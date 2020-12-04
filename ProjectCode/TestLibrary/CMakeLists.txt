
project(TestCase)

set(hdrFiles
QAppTestSetup.h
LabelSliderTestFixture.h
)


set(srcFiles
TestLinkLibrary.cpp
TestLib.cpp
QtTestsUtil.cpp
)

add_executable(TestCase ${hdrFiles} ${srcFiles})


set_property(TARGET TestCase PROPERTY CXX_STANDARD ${CppVersion})

target_link_libraries(TestCase gtest gtest_main ${libProject} )
