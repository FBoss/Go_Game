#ifndef UNDOCOMMANDTEST_H
#define UNDOCOMMANDTEST_H

#include "UndoCommand.h"

namespace {
    TEST(UndoCommand, OutputWithId) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::UndoCommand{256});

    EXPECT_EQ("256 undo\n", test);
}

TEST(UndoCommand, OutputWithoutId) {

auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::UndoCommand{});

EXPECT_EQ("undo\n", test);
}
} //namespace


#endif //UNDOCOMMANDTEST_H
