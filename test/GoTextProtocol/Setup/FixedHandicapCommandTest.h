#ifndef FIXEDHANDICAPCOMMANDTEST_H
#define FIXEDHANDICAPCOMMANDTEST_H

#include "FixedHandicapCommand.h"

namespace {
    TEST(FixedHandicap, OutputWithId    ) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::FixedHandicapCommand{256, 4});

    EXPECT_EQ("256 fixed_handicap 4\n", test);
}

TEST(FixedHandicap, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::FixedHandicapCommand{-4});

EXPECT_EQ("fixed_handicap -4\n", test);
}
} //namespace


#endif //FINALSCORECOMMANDTEST_H
