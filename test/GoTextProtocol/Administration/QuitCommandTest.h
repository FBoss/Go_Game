#ifndef QUITCOMMANDTEST_H
#define QUITCOMMANDTEST_H

#include "QuitCommand.h"

namespace {
TEST(QuitCommand, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::QuitCommand{256});

  EXPECT_EQ("256 quit\n", test);
}

TEST(QuitCommand, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::QuitCommand{});

  EXPECT_EQ("quit\n", test);
}
} // namespace

#endif // QUITCOMMANDTEST_H
