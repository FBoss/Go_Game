#ifndef COMMANDTEST_H
#define COMMANDTEST_H

#include "Command.h"

namespace {
    TEST(Command, OutputWithId    ) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::Command{256, "test"});

    EXPECT_EQ("256 test", test);
}

TEST(Command, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::Command{std::nullopt, "test"});

EXPECT_EQ("test", test);
}
}

#endif //COMMANDTEST_H
