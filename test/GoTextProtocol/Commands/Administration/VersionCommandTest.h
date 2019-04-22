#ifndef VERSIONCOMMANDTEST_H
#define VERSIONCOMMANDTEST_H

#include "VersionCommand.h"

namespace {
TEST(VersionCommand, OutputWithId) {
  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::VersionCommand{256});

  EXPECT_EQ("256 version\n", test);
}

TEST(VersionCommand, OutputWithoutId) {

  auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::VersionCommand{});

  EXPECT_EQ("version\n", test);
}
} // namespace

#endif // VERSIONCOMMANDTEST_H
