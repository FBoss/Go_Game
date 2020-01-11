#include "GameEngineTest.h"

TEST_F(GameEngineVerification, point_of_play_boardsize) {
  const auto dimension = mEngine.board().getDimension();

  mEngine.play_black(0, 0);
  mEngine.play_white(0, dimension.column - 1);
  mEngine.play_black(dimension.row - 1, 0);
  mEngine.play_white(dimension.row - 1, dimension.column - 1);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, dimension.column - 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(dimension.row - 1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(dimension.row - 1, dimension.column - 1), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_unoccupied_only) {
  mEngine.play_black(0, 0);
  mEngine.play_white(0, 1);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(0, 0););
  EXPECT_ANY_THROW(mEngine.play_black(0, 1););
  EXPECT_ANY_THROW(mEngine.play_white(0, 0););
  EXPECT_ANY_THROW(mEngine.play_white(0, 1););

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern1) {
  mEngine.play_white(0, 2);
  mEngine.play_black(0, 1);
  mEngine.play_white(1, 1);
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 0);

  ASSERT_EQ(mEngine.board().get(0, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(0, 0););

  EXPECT_EQ(mEngine.board().get(0, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern2) {
  mEngine.play_white(1, 0);
  mEngine.play_black_pass();
  mEngine.play_white(4, 0);
  mEngine.play_black_pass();
  mEngine.play_white(2, 1);
  mEngine.play_black(3, 0);
  mEngine.play_white(3, 1);

  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(2, 0););

  EXPECT_EQ(mEngine.board().get(1, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern3) {
  mEngine.play_white(1, 0);
  mEngine.play_black_pass();
  mEngine.play_white(2, 1);
  mEngine.play_black_pass();
  mEngine.play_white(3, 0);

  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(2, 0););

  EXPECT_EQ(mEngine.board().get(1, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern4) {
  mEngine.play_white(0, 1);
  mEngine.play_black_pass();
  mEngine.play_white(1, 0);

  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(0, 0););

  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern5) {
  mEngine.play_white(1, 2);
  mEngine.play_black_pass();
  mEngine.play_white(2, 1);
  mEngine.play_black_pass();
  mEngine.play_white(2, 3);
  mEngine.play_black_pass();
  mEngine.play_white(3, 2);

  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(2, 2););

  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern6) {
  mEngine.play_white(1, 2);
  mEngine.play_black_pass();
  mEngine.play_white(2, 1);
  mEngine.play_black(2, 2);
  mEngine.play_white(2, 3);
  mEngine.play_black_pass();
  mEngine.play_white(3, 1);
  mEngine.play_black_pass();
  mEngine.play_white(3, 3);
  mEngine.play_black_pass();
  mEngine.play_white(4, 1);
  mEngine.play_black(4, 2);
  mEngine.play_white(4, 3);
  mEngine.play_black_pass();
  mEngine.play_white(5, 2);

  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(5, 2), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(3, 2););

  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(5, 2), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_pattern7) {
  mEngine.play_white(1, 3);
  mEngine.play_black_pass();
  mEngine.play_white(2, 2);
  mEngine.play_black(2, 3);
  mEngine.play_white(2, 4);
  mEngine.play_black_pass();
  mEngine.play_white(3, 1);
  mEngine.play_black(3, 2);
  mEngine.play_white_pass();
  mEngine.play_black(3, 4);
  mEngine.play_white(3, 5);
  mEngine.play_black_pass();
  mEngine.play_white(4, 2);
  mEngine.play_black(4, 3);
  mEngine.play_white(4, 4);
  mEngine.play_black_pass();
  mEngine.play_white(5, 3);

  ASSERT_EQ(mEngine.board().get(1, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 5), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(5, 3), Stone::white);

  EXPECT_ANY_THROW(mEngine.play_black(3, 3););

  EXPECT_EQ(mEngine.board().get(1, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 4), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 4), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 5), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(4, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 4), Stone::white);
  EXPECT_EQ(mEngine.board().get(5, 3), Stone::white);
}

TEST_F(GameEngineVerification, point_of_play_valid_pattern1) {
  mEngine.play_black(0, 1);
  mEngine.play_white(0, 2);
  mEngine.play_black_pass();
  mEngine.play_white(0, 3);
  mEngine.play_black(0, 4);
  // mEngine.play_white(0,5);
  mEngine.play_white(0, 6);
  mEngine.play_black(0, 7);
  mEngine.play_white_pass();

  mEngine.play_black(1, 1);
  mEngine.play_white(1, 2);
  mEngine.play_black(1, 3);
  mEngine.play_white_pass();
  // mEngine.play_white(1,4);
  mEngine.play_black(1, 5);
  mEngine.play_white(1, 6);
  mEngine.play_black(1, 7);
  mEngine.play_white_pass();

  mEngine.play_black(2, 1);
  mEngine.play_white(2, 2);
  mEngine.play_black_pass();
  mEngine.play_white(2, 3);
  mEngine.play_black(2, 4);
  mEngine.play_white(2, 5);
  mEngine.play_black_pass();
  mEngine.play_white(2, 6);
  mEngine.play_black(2, 7);
  mEngine.play_white_pass();

  mEngine.play_black(3, 1);
  // mEngine.play_white(3,2);
  mEngine.play_white(3, 3);
  mEngine.play_black_pass();
  mEngine.play_white(3, 4);
  mEngine.play_black_pass();
  mEngine.play_white(3, 5);
  // mEngine.play_white(3,6);
  mEngine.play_black(3, 7);
  mEngine.play_white_pass();

  // mEngine.play_white(4,1);
  mEngine.play_black(4, 2);
  mEngine.play_white_pass();
  mEngine.play_black(4, 3);
  mEngine.play_white_pass();
  mEngine.play_black(4, 4);
  mEngine.play_white_pass();
  mEngine.play_black(4, 5);
  mEngine.play_white_pass();
  mEngine.play_black(4, 6);
  // mEngine.play_white(4,7);

  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 4), Stone::black);
  // ASSERT_EQ(mEngine.board().get(0,5), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 7), Stone::black);

  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 3), Stone::black);
  // ASSERT_EQ(mEngine.board().get(1,4), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 5), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 7), Stone::black);

  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 5), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 7), Stone::black);

  ASSERT_EQ(mEngine.board().get(3, 1), Stone::black);
  // ASSERT_EQ(mEngine.board().get(3,2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 5), Stone::white);
  // ASSERT_EQ(mEngine.board().get(3,6), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 7), Stone::black);

  // ASSERT_EQ(mEngine.board().get(4,1), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 5), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 6), Stone::black);
  // ASSERT_EQ(mEngine.board().get(4,7), Stone::black);

  mEngine.play_white(3, 6);
  mEngine.play_black(1, 4);

  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 4), Stone::black);
  // ASSERT_EQ(mEngine.board().get(0,5), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(0, 7), Stone::black);

  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 5), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 7), Stone::black);

  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 5), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 7), Stone::black);

  ASSERT_EQ(mEngine.board().get(3, 1), Stone::black);
  // ASSERT_EQ(mEngine.board().get(3,2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 5), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 6), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 7), Stone::black);

  // ASSERT_EQ(mEngine.board().get(4,1), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 5), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 6), Stone::black);
  // ASSERT_EQ(mEngine.board().get(4,7), Stone::black);
}
