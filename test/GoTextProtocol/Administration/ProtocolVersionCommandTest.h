#ifndef PROTOCOLVERSIONCOMMANDTEST_H
#define PROTOCOLVERSIONCOMMANDTEST_H

#include "ProtocolVersionCommand.h"

namespace {
    TEST(ProtocolVersionCommand, OutputWithId) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ProtocolVersionCommand{256});

    EXPECT_EQ("256 protocol_version\n", test);
}

TEST(ProtocolVersionCommand, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::ProtocolVersionCommand{});

EXPECT_EQ("protocol_version\n", test);
}
}

#endif //PROTOCOLVERSIONCOMMANDTEST_H
