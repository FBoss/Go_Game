#ifndef BOARDSIZECOMMANDTEST_H
#define BOARDSIZECOMMANDTEST_H

#include "BoardSizeCommand.h"

namespace {
    TEST(BoardSize, OutputWithId    ) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::BoardSizeCommand{256, 4});

    EXPECT_EQ("256 boardsize 4\n", test);
}

TEST(BoardSize, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::BoardSizeCommand{4});

EXPECT_EQ("boardsize 4\n", test);
}
} //namespace


#endif //BOARDSIZECOMMANDTEST_H
