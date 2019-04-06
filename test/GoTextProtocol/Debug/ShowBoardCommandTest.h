#ifndef SHOWBOARDCOMMANDTEST_H
#define SHOWBOARDCOMMANDTEST_H

#include "ShowBoardCommand.h"

namespace {
    TEST(ShowboardCommand, OutputWithId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ShowBoardCommand{256});

        EXPECT_EQ("256 showboard\n", test);
    }

    TEST(ShowboardCommand, OutputWithoutId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ShowBoardCommand{});

        EXPECT_EQ("showboard\n", test);
    }
}


#endif //SHOWBOARDCOMMANDTEST_H
