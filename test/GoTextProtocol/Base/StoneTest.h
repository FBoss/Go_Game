#ifndef STONECOMMANDTEST_H
#define STONECOMMANDTEST_H

#include "Stone.h"
#include "GTPStoneUtils.h"

namespace {
    TEST(Stone, Black) {
    auto test = Go::GoTextProtocol::to_string(Go::Stone::black);

    EXPECT_EQ("B", test);
}

TEST(Stone, White) {

auto test = Go::GoTextProtocol::to_string(Go::Stone::white);

EXPECT_EQ("W", test);
}

TEST(Stone, Empty) {

auto test = Go::GoTextProtocol::to_string(Go::Stone::empty);

EXPECT_EQ("E", test);
}


} //namespace


#endif //STONECOMMANDTEST_H
