#ifndef PLAYCOMMANDTEST_H
#define PLAYCOMMANDTEST_H

#include "PlayCommand.h"
#include "Move.h"

namespace {
    TEST(PlayCommand, PassOutputWithId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlayCommand{256});

        EXPECT_EQ("256 play pass\n", test);
    }

    TEST(PlayCommand, PassOutputWithoutId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlayCommand{});

        EXPECT_EQ("play pass\n", test);
    }

    TEST(PlayCommand, VertexMoveOutputWitId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlayCommand{256, Go::GoTextProtocol::VertexMove{Go::Stone::white, Go::GoTextProtocol::Vertex{1,1}}});

        EXPECT_EQ("256 play W B2\n", test);
    }

    TEST(PlayCommand, VertexMoveOutputWithoutId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlayCommand{Go::GoTextProtocol::VertexMove{Go::Stone::white, Go::GoTextProtocol::Vertex{1,1}}});

        EXPECT_EQ("play W B2\n", test);
    }

    TEST(PlayCommand, ResignMoveOutputWitId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlayCommand{256, Go::GoTextProtocol::ResignMove{}});

        EXPECT_EQ("256 play resign\n", test);
    }

    TEST(PlayCommand, ResignMoveOutputWithoutId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlayCommand{Go::GoTextProtocol::ResignMove{}});

        EXPECT_EQ("play resign\n", test);
    }
}


#endif //PLAYCOMMANDTEST_H
