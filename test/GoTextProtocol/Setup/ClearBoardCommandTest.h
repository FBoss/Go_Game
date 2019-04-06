#ifndef CLEARBOARDCOMMANDTEST_H
#define CLEARBOARDCOMMANDTEST_H

#include "ClearBoardCommand.h"

namespace {
TEST(ClearBoardCommand, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ClearBoardCommand{256});

  EXPECT_EQ("256 clear_board\n", test);
}

TEST(ClearBoardCommand, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ClearBoardCommand{});

  EXPECT_EQ("clear_board\n", test);
}
} // namespace

#endif // CLEARBOARDCOMMANDTEST_H
