#ifndef LISTCOMMANDSCOMMANDTEST_H
#define LISTCOMMANDSCOMMANDTEST_H

#include "ListCommandsCommand.h"

namespace {
TEST(ListCommandsCommand, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ListCommandsCommand{256});

  EXPECT_EQ("256 list_commands\n", test);
}

TEST(ListCommandsCommand, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ListCommandsCommand{});

  EXPECT_EQ("list_commands\n", test);
}
} // namespace

#endif // LISTCOMMANDSCOMMANDTEST_H
