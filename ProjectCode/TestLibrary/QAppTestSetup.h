#include <gtest/gtest.h>

#include <iostream>
#include <QApplication>
#include <QSignalSpy>

class QAppFixture : public testing::Test
{
protected:
    static void SetUpTestSuite()
    {
        char * argv[4];
        int argc = 0;
        app = new QApplication(argc,argv);
    }

    static void TearDownTestSuite() {
        delete app;
    }



// You can define per-test set-up logic as usual.
//virtual void SetUp() {  std::cout << "Suit up" << std::endl; }

// You can define per-test tear-down logic as usual.
//virtual void TearDown() { std::cout << "Tear down" << std::endl;}

static  QApplication * app;

};
QApplication* QAppFixture::app   = nullptr;

