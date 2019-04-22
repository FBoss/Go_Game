#ifndef KOMICOMMANDTEST_H
#define KOMICOMMANDTEST_H

#include "KomiCommand.h"

namespace {
TEST(Komi, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::KomiCommand{256, 4.5});

  EXPECT_EQ("256 komi 4.5\n", test);
}

TEST(Komi, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::KomiCommand{4});

  EXPECT_EQ("komi 4\n", test);
}
} // namespace

#endif // KOMICOMMANDTEST_H
