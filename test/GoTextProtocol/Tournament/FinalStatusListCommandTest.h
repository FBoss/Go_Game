#ifndef FINALSTATUSLISTCOMMANDTEST_H
#define FINALSTATUSLISTCOMMANDTEST_H

#include "FinalStatusListCommand.h"

namespace {
    TEST(GameStatus, alive) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GameStatus::alive);

        EXPECT_EQ("alive", test);
    }

    TEST(GameStatus, dead) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GameStatus::dead);
        EXPECT_EQ("dead", test);
    }
    TEST(GameStatus, seki) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::GameStatus::seki);
        EXPECT_EQ("seki", test);
    }

    TEST(FinalStatusList, CommandWithId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::FinalStatusListCommand{256, Go::GoTextProtocol::GameStatus ::alive});
        EXPECT_EQ("256 final_status_list alive\n", test);
    }
    TEST(FinalStatusList, CommandWithoutId) {
        auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::FinalStatusListCommand{Go::GoTextProtocol::GameStatus::dead});
        EXPECT_EQ("final_status_list dead\n", test);
    }

    } //namespace


#endif //FINALSTATUSLISTCOMMANDTEST_H
