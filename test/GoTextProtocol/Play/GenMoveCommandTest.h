#ifndef GENMOVECOMMANDTEST_H
#define GENMOVECOMMANDTEST_H

#include "Stone.h"
#include "GenMoveCommand.h"

namespace Go {

    TEST(GenMoveCommand, OutputWithIdBlack) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GenMoveCommand{256, Go::Stone::black});

        EXPECT_EQ("256 genmove B\n", test);
    }

    TEST(GenMoveCommand, OutputWithoutIdBlack) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GenMoveCommand{Go::Stone::black});

        EXPECT_EQ("genmove B\n", test);
    }
    TEST(GenMoveCommand, OutputWithIdWhite) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GenMoveCommand{256, Go::Stone::white});

        EXPECT_EQ("256 genmove W\n", test);
    }

    TEST(GenMoveCommand, OutputWithoutIdWhite) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GenMoveCommand{Go::Stone::white});

        EXPECT_EQ("genmove W\n", test);
    }
    TEST(GenMoveCommand, OutputWithIdEmpty) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GenMoveCommand{256, Go::Stone::empty});

        EXPECT_EQ("256 genmove E\n", test);
    }

    TEST(GenMoveCommand, OutputWithoutIdEmpty) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GenMoveCommand{Go::Stone::empty});

        EXPECT_EQ("genmove E\n", test);
    }
} // namespace Go


#endif //GENMOVECOMMANDTEST_H
