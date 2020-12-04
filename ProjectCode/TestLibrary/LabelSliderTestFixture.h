#pragma once
#include "util/LabelSlider.h"
#include <QCoreApplication>
#include <QKeyEvent>
#include <QTest>

//Here we use test fixtures
class LabelSliderTestFixture
{

private:
    LabelSlider m_labelSlider;
    std::unique_ptr<QSignalSpy> m_activatedSpy;

public:
    //Set up signalspy
    LabelSliderTestFixture()
    {
        m_activatedSpy = std::make_unique<QSignalSpy>(&m_labelSlider, &LabelSlider::valueChanged);
    }


    std::pair<bool, std::string> IsSpyIntVal(int val)
    {

        if(!m_activatedSpy->isValid())
            return std::make_pair(false, "Signal Spy not active");

        auto arguments = m_activatedSpy->first();
        auto argument = arguments.at(0);

        if(!(argument.type() == QVariant::Int))
            return std::make_pair(false, "Wrong type emitted");

        if(!(argument.toInt() == val))
            return std::make_pair(false, std::string("Value: ") + std::to_string(argument.toInt()) + std::string(" emitted instead of: " + std::to_string(val)));

        return std::make_pair(true, "");
    }


    void ChangeLabelSliderValueTo(int val)
    {
        m_labelSlider.SetValue(val);
    }

};
