#ifndef TIMESETTINGSCOMMANDTEST_H
#define TIMESETTINGSCOMMANDTEST_H

#include "TimeSettingsCommand.h"

namespace {
    TEST(TimeSettingsCommand, OutputWithId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeSettingsCommand{256, 0, 0, 0});

        EXPECT_EQ("256 time_settings 0 0 0\n", test);
    }

    TEST(TimeSettingsCommand, OutputWithoutId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeSettingsCommand{256, 256, 256});

        EXPECT_EQ("time_settings 256 256 256\n", test);
    }
}


#endif //TIMESETTINGSCOMMANDTEST_H
