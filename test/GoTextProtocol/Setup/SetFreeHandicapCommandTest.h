#ifndef SETFREEHANDICAPCOMMANDTEST_H
#define SETFREEHANDICAPCOMMANDTEST_H

#include "SetFreeHandicapCommand.h"

namespace {
    TEST(SetFreeHandicapCommand, OutputWithIdEmptyVertices) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::SetFreeHandicapCommand<0>{256, {}});

    EXPECT_EQ("256 set_free_handicap\n", test);
}

TEST(SetFreeHandicapCommand, OutputWithoutIdEmptyVertices) {

auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::SetFreeHandicapCommand<0>{{}});

EXPECT_EQ("set_free_handicap\n", test);
}

    TEST(SetFreeHandicapCommand, OutputWithoutId5Vertices) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::SetFreeHandicapCommand<5>{{Go::GoTextProtocol::Vertex{0,0}, Go::GoTextProtocol::Vertex{1,1}, Go::GoTextProtocol::Vertex{2,2}, Go::GoTextProtocol::Vertex{3,3}, Go::GoTextProtocol::Vertex{4,4}}});

        EXPECT_EQ("set_free_handicap A1 B2 C3 D4 E5\n", test);
    }

} //namespace


#endif //SETFREEHANDICAPCOMMANDTEST_H
