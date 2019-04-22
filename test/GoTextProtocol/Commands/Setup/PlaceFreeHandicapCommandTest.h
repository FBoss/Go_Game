#ifndef PLACEFREEHANDICAPCOMMANDTEST_H
#define PLACEFREEHANDICAPCOMMANDTEST_H

#include "PlaceFreeHandicapCommand.h"

namespace {
TEST(PlaceFreeHandicapCommand, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlaceFreeHandicapCommand{256, 4});

  EXPECT_EQ("256 place_free_handicap 4\n", test);
}

TEST(PlaceFreeHandicapCommand, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::PlaceFreeHandicapCommand{-4});

  EXPECT_EQ("place_free_handicap -4\n", test);
}
} // namespace

#endif // PLACEFREEHANDICAPCOMMANDTEST_H
