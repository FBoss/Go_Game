#include "GameEngineTest.h"

TEST_F(GameEngineVerification, capture_pattern1) {
  mEngine.play_black(0, 1);
  mEngine.play_white(0, 0);

  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 0), Stone::white);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(1, 0);

  EXPECT_EQ(mEngine.board().get(0, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));
}

TEST_F(GameEngineVerification, capture_pattern2) {
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 0);
  mEngine.play_black(3, 0);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(2, 1);

  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));
}

TEST_F(GameEngineVerification, capture_pattern3) {
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 0);
  mEngine.play_black(2, 1);
  mEngine.play_white(3, 0);
  mEngine.play_black(4, 0);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 0), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(3, 1);

  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{2, 0}));
}

TEST_F(GameEngineVerification, capture_pattern4) {
  mEngine.play_black(0, 2);
  mEngine.play_white(0, 1);
  mEngine.play_black(1, 1);
  mEngine.play_white(1, 0);
  mEngine.play_black(2, 0);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(0, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(0, 0);

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{2, 0}));
}
