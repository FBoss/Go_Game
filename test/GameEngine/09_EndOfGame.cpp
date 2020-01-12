#include "GameEngineTest.h"

TEST_F(GameEngineVerification, endOfGame_Capture_2_3) {
  mEngine.play_white(1, 1);
  mEngine.play_black(0, 0);
  mEngine.play_white(2, 0);
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 2);
  mEngine.play_black(3, 0);
  mEngine.play_white(3, 3);
  mEngine.play_black(3, 1);
  mEngine.play_white(4, 0);
  mEngine.play_black(3, 2);
  mEngine.play_white(4, 1);
  mEngine.play_black_pass();
  mEngine.play_white(4, 2);
  mEngine.play_black_pass();

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::white);
  ASSERT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));
  ASSERT_EQ(mEngine.state(), (GameState::turn_white));

  mEngine.play_white(0, 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::white);
  EXPECT_EQ(mEngine.score(), (Score{0, 2, std::nullopt, ScoreType::ongoing}));

  mEngine.play_black_pass();
  mEngine.play_white(2, 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::white);

  EXPECT_EQ(mEngine.state(), (GameState::game_over));
  EXPECT_EQ(mEngine.score(), (Score{0, 5, Stone::white, ScoreType::score}));
}

TEST_F(GameEngineVerification, endOfGame_Capture_5) {
  mEngine.play_white(0, 1);
  mEngine.play_black(0, 0);
  mEngine.play_white(1, 2);
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 0);
  mEngine.play_black(1, 1);
  mEngine.play_white(3, 1);
  mEngine.play_black(2, 1);
  mEngine.play_white(3, 2);
  mEngine.play_black(2, 2);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::white);
  ASSERT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));
  ASSERT_EQ(mEngine.state(), (GameState::turn_white));

  mEngine.play_white(2, 3);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::white);

  EXPECT_EQ(mEngine.state(), (GameState::game_over));
  EXPECT_EQ(mEngine.score(), (Score{0, 5, Stone::white, ScoreType::score}));
}

TEST_F(GameEngineVerification, endOfGame_Capture_6) {
  mEngine.play_black(0, 0);
  mEngine.play_white(0, 2);
  mEngine.play_black(0, 1);
  mEngine.play_white(1, 2);
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 2);
  mEngine.play_black(1, 1);
  mEngine.play_white(3, 0);
  mEngine.play_black(2, 0);
  mEngine.play_white_pass();
  mEngine.play_black(2, 1);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::white);
  ASSERT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));
  ASSERT_EQ(mEngine.state(), (GameState::turn_white));

  mEngine.play_white(3, 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::white);

  EXPECT_EQ(mEngine.state(), (GameState::game_over));
  EXPECT_EQ(mEngine.score(), (Score{0, 6, Stone::white, ScoreType::score}));
}

TEST_F(GameEngineVerification, endOfGame_Capture_2_2_1) {
  mEngine.play_black(0, 2);
  mEngine.play_white(0, 0);
  mEngine.play_black(1, 1);
  mEngine.play_white(0, 1);
  mEngine.play_black(2, 1);
  mEngine.play_white(1, 2);
  mEngine.play_black(2, 2);
  mEngine.play_white(2, 0);
  mEngine.play_black(3, 1);
  mEngine.play_white(3, 0);
  mEngine.play_black(4, 0);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 0), Stone::black);
  ASSERT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));
  ASSERT_EQ(mEngine.state(), (GameState::turn_black));

  mEngine.play_black(1, 0);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::black);

  EXPECT_EQ(mEngine.state(), (GameState::turn_white));
  EXPECT_EQ(mEngine.score(), (Score{4, 0, std::nullopt, ScoreType::ongoing}));

  mEngine.play_white_pass();
  mEngine.play_black(1, 3);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::black);

  EXPECT_EQ(mEngine.state(), (GameState::game_over));
  EXPECT_EQ(mEngine.score(), (Score{5, 0, Stone::black, ScoreType::score}));
}

TEST_F(GameEngineVerification, endOfGame_consecutivePass_blackContinue) {
  mEngine.play_white_pass();
  mEngine.play_black_pass();

  ASSERT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));
  ASSERT_EQ(mEngine.state(), (GameState::end_of_game));

  mEngine.play_black(0, 0);
  mEngine.play_white(0, 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);

  EXPECT_EQ(mEngine.state(), GameState::turn_black);
}

TEST_F(GameEngineVerification, endOfGame_consecutivePass_whiteContinue) {
  mEngine.play_white_pass();
  mEngine.play_black_pass();

  ASSERT_EQ(mEngine.score(), (Score{0, 0, std::nullopt, ScoreType::ongoing}));
  ASSERT_EQ(mEngine.state(), (GameState::end_of_game));

  mEngine.play_white(0, 0);
  mEngine.play_black(0, 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::black);

  EXPECT_EQ(mEngine.state(), GameState::turn_white);
}
