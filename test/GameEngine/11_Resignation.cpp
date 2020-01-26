#include "GameEngineTest.h"

TEST_F(GameEngineVerification, resign_start_of_game) {

  ASSERT_EQ(mEngine.state(), GameState::start);

  mEngine.play_black_resign();

  EXPECT_EQ(mEngine.state(), GameState::game_over);
  EXPECT_EQ(mEngine.score(), (Score{0, 0, Stone::white, ScoreType::win_by_resign}));
}

TEST_F(GameEngineVerification, resign_playing) {

  mEngine.play_white(0, 0);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::white);
  ASSERT_EQ(mEngine.state(), GameState::turn_black);

  mEngine.play_white_resign();

  EXPECT_EQ(mEngine.state(), GameState::game_over);
  EXPECT_EQ(mEngine.score(), (Score{0, 0, Stone::black, ScoreType::win_by_resign}));
}

TEST_F(GameEngineVerification, resign_end_of_game) {

  mEngine.play_black_pass();
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.state(), GameState::end_of_game);

  mEngine.play_white_resign();

  EXPECT_EQ(mEngine.state(), GameState::game_over);
  EXPECT_EQ(mEngine.score(), (Score{0, 0, Stone::black, ScoreType::win_by_resign}));
}

TEST_F(GameEngineVerification, resign_game_over) {

  mEngine.play_white_resign();

  ASSERT_EQ(mEngine.state(), GameState::game_over);

  EXPECT_ANY_THROW(mEngine.play_black_resign());

  EXPECT_EQ(mEngine.state(), GameState::game_over);
  EXPECT_EQ(mEngine.score(), (Score{0, 0, Stone::black, ScoreType::win_by_resign}));
}
