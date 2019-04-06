#ifndef NAMECOMMANDTEST_H
#define NAMECOMMANDTEST_H

#include "NameCommand.h"

namespace {
TEST(NameCommand, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::NameCommand{256});

  EXPECT_EQ("256 name\n", test);
}

TEST(NameCommand, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::NameCommand{});

  EXPECT_EQ("name\n", test);
}
} // namespace

#endif // NAMECOMMANDTEST_H
