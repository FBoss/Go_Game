#include "GameEngineTest.h"

TEST_F(GameEngineVerification, play_Consecutive_move) {
  mEngine.play_black(0, 0);
  EXPECT_ANY_THROW(mEngine.play_black(0, 1););

  mEngine.play_white(1, 0);
  EXPECT_ANY_THROW(mEngine.play_white(1, 1););

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::empty);
}

TEST_F(GameEngineVerification, play_Consecutive_move_with_pass) {
  mEngine.play_black(0, 0);
  mEngine.play_white_pass();
  EXPECT_ANY_THROW(mEngine.play_white_pass(););

  mEngine.play_black(0, 1);
  mEngine.play_white(1, 0);

  mEngine.play_black_pass();
  EXPECT_ANY_THROW(mEngine.play_black_pass(););

  mEngine.play_white(1, 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::white);
}
