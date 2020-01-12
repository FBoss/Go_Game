#include "GameEngineTest.h"

TEST_F(GameEngineVerification, ko_pattern1) {
  mEngine.play_black(1, 1);
  mEngine.play_white(0, 1);
  mEngine.play_black(2, 0);
  mEngine.play_white(1, 0);
  mEngine.play_black(2, 1);
  mEngine.play_white(1, 2);

  // first capture
  mEngine.play_black(0, 0);

  ASSERT_EQ(mEngine.board().get(0, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));

  EXPECT_ANY_THROW(mEngine.play_white(1, 0));

  EXPECT_EQ(mEngine.board().get(0, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));
}

TEST_F(GameEngineVerification, ko_pattern2) {
  mEngine.play_white(2, 2);
  mEngine.play_black(1, 2);
  mEngine.play_white(3, 1);
  mEngine.play_black(2, 1);
  mEngine.play_white(3, 3);
  mEngine.play_black(2, 3);
  mEngine.play_white(4, 2);

  // first capture
  mEngine.play_black(3, 2);

  ASSERT_EQ(mEngine.board().get(1, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::empty);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::white);
  ASSERT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));

  EXPECT_ANY_THROW(mEngine.play_white(2, 2));

  EXPECT_EQ(mEngine.board().get(1, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::white);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));
}

TEST_F(GameEngineVerification, ko_pattern3) {
  mEngine.play_white(0, 2);
  mEngine.play_black(0, 1);
  mEngine.play_white(0, 4);
  mEngine.play_black(1, 1);
  mEngine.play_white(1, 3);
  mEngine.play_black(1, 2);
  mEngine.play_white(1, 4);

  // first capture
  mEngine.play_black(0, 3);

  ASSERT_EQ(mEngine.board().get(0, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 2), Stone::empty);
  ASSERT_EQ(mEngine.board().get(0, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(0, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 4), Stone::white);
  ASSERT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));

  EXPECT_ANY_THROW(mEngine.play_white(0, 2));

  EXPECT_EQ(mEngine.board().get(0, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(0, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(0, 4), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 3), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 4), Stone::white);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));
}
