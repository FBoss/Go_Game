#ifndef TIMELEFTCOMMANDTEST_H
#define TIMELEFTCOMMANDTEST_H

#include "TimeLeftCommand.h"
#include "Stone.h"

namespace {
    TEST(TimeLeftCommand, OutputWithIdBlack) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeLeftCommand{256, Go::Stone::black, 0, 0});

        EXPECT_EQ("256 time_left B 0 0\n", test);
    }

    TEST(TimeLeftCommand, OutputWithoutIdBlack) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeLeftCommand{Go::Stone::black, 256, 256});

        EXPECT_EQ("time_left B 256 256\n", test);
    }

    TEST(TimeLeftCommand, OutputWithIdWhite) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeLeftCommand{256, Go::Stone::white, 0, 0});

        EXPECT_EQ("256 time_left W 0 0\n", test);
    }

    TEST(TimeLeftCommand, OutputWithoutIdWhite) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeLeftCommand{Go::Stone::white, 256, 256});

        EXPECT_EQ("time_left W 256 256\n", test);
    }

    TEST(TimeLeftCommand, OutputWithIdEmpty) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeLeftCommand{256, Go::Stone::empty, 0, 0});

        EXPECT_EQ("256 time_left E 0 0\n", test);
    }

    TEST(TimeLeftCommand, OutputWithoutIdEmpty) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::TimeLeftCommand{Go::Stone::empty, 256, 256});

        EXPECT_EQ("time_left E 256 256\n", test);
    }
} //namespace


#endif //TIMELEFTCOMMANDTEST_H
