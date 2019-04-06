#ifndef FINALSCORECOMMANDTEST_H
#define FINALSCORECOMMANDTEST_H

#include "FinalScoreCommand.h"

namespace {
    TEST(FinalScoreCommand, OutputWithId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::FinalScoreCommand{256});

        EXPECT_EQ("256 final_score\n", test);
    }

    TEST(FinalScoreCommand, OutputWithoutId) {

        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::FinalScoreCommand{});

        EXPECT_EQ("final_score\n", test);
    }
} //namespace


#endif //FINALSCORECOMMANDTEST_H
