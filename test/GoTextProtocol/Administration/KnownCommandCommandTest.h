#ifndef KNOWNCOMMANDCOMMANDTEST_H
#define KNOWNCOMMANDCOMMANDTEST_H

#include "KnownCommandCommand.h"

namespace {
    TEST(KnownCommandCommand, OutputWithId) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::KnownCommandCommand{256});

    EXPECT_EQ("256 known_command\n", test);
}

TEST(KnownCommandCommand, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::KnownCommandCommand{});

EXPECT_EQ("known_command\n", test);
}
} //namespace



#endif //KNOWNCOMMANDCOMMANDTEST_H
