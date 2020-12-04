#include <gtest/gtest.h>
#include <QSignalSpy>

#include "QAppTestSetup.h"
#include "LabelSliderTestFixture.h"


TEST_F(QAppFixture, TestLabelSliderValueChanged)
{
    int val = 120;
    LabelSliderTestFixture tf;

    tf.ChangeLabelSliderValueTo(val);

    EXPECT_EQ(tf.IsSpyIntVal(val).first,true) <<tf.IsSpyIntVal(val).second;
}



