#ifndef REGGENMOVECOMMANDTEST_H
#define REGGENMOVECOMMANDTEST_H

#include "RegGenMoveCommand.h"
#include "Stone.h"

namespace {
TEST(RegGenMoveCommand, OutputWithIdWhite) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::RegGenMoveCommand{256, Go::Stone::white});

  EXPECT_EQ("256 reg_genmove W\n", test);
}

TEST(RegGenMoveCommand, OutputWithoutIdBlack) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::RegGenMoveCommand{Go::Stone::black});

  EXPECT_EQ("reg_genmove B\n", test);
}

TEST(RegGenMoveCommand, OutputWithoutIdEmpty) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::RegGenMoveCommand{Go::Stone::empty});

  EXPECT_EQ("reg_genmove E\n", test);
}

} // namespace

#endif // REGGENMOVECOMMANDTEST_H
