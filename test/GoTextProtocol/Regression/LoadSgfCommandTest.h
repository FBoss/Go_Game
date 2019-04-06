#ifndef LOADSGFCOMMANDTEST_H
#define LOADSGFCOMMANDTEST_H

#include "LoadSgfCommand.h"

namespace {
    TEST(LoadSgfCommand, OutputWithId) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::LoadSgfCommand{256, "file", 5});

    EXPECT_EQ("256 loadsgf file 5\n", test);
}

TEST(LoadSgfCommand, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::LoadSgfCommand{"file", 0});

EXPECT_EQ("loadsgf file 0\n", test);
}

    TEST(LoadSgfCommand, EmptyFileName) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::LoadSgfCommand{"", 0});

        EXPECT_EQ("loadsgf  0\n", test);
    }
}


#endif //LOADSGFCOMMANDTEST_H
