#ifndef MOVECOMMANDTEST_H
#define MOVECOMMANDTEST_H

#include "Move.h"
#include "Stone.h"

namespace {
    TEST(VertexMove, BlackDefaultVertex) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::VertexMove{Go::Stone::black, {}});

        EXPECT_EQ("B A1", test);
    }

    TEST(VertexMove, White0x0) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::VertexMove{Go::Stone::white, {0,0}});

        EXPECT_EQ("W A1", test);
    }

    TEST(VertexMove, Empty1x1) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::VertexMove{Go::Stone::empty, {1,1}});

        EXPECT_EQ("E B2", test);
    }


    TEST(PassMove, Default) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PassMove{});

        EXPECT_EQ("pass", test);
    }
    TEST(ResignMove, Default) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ResignMove{});

        EXPECT_EQ("resign", test);
    }

} //namespace


#endif //MOVECOMMANDTEST_H
