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

TEST_F(GameEngineVerification, capture_pattern5) {
  mEngine.play_black(1, 0);
  mEngine.play_white(2, 0);
  mEngine.play_black(2, 1);
  mEngine.play_white(3, 0);
  mEngine.play_black(4, 0);
  mEngine.play_white(3, 1);
  mEngine.play_black(4, 1);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(1, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 1), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(3, 2);

  EXPECT_EQ(mEngine.board().get(1, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 1), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{3, 0}));
}

TEST_F(GameEngineVerification, capture_pattern6) {
  mEngine.play_black(1, 2);
  mEngine.play_white(2, 2);
  mEngine.play_black(2, 1);
  mEngine.play_white(3, 2);
  mEngine.play_black(3, 1);
  mEngine.play_white_pass();
  mEngine.play_black(3, 3);
  mEngine.play_white_pass();
  mEngine.play_black(4, 2);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(1, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(2, 3);

  EXPECT_EQ(mEngine.board().get(1, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{2, 0}));
}

TEST_F(GameEngineVerification, capture_pattern7) {
  mEngine.play_black(1, 2);
  mEngine.play_white(2, 2);
  mEngine.play_black(2, 3);
  mEngine.play_white_pass();
  mEngine.play_black(3, 2);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(1, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::black);
  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(2, 1);

  EXPECT_EQ(mEngine.board().get(1, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::black);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{1, 0}));
}

TEST_F(GameEngineVerification, capture_pattern8) {

  mEngine.play_white(1, 0);
  mEngine.play_black(2, 1);
  mEngine.play_white(1, 1);
  mEngine.play_black(3, 2);
  mEngine.play_white(1, 2);
  mEngine.play_black(4, 0);
  mEngine.play_white(2, 2);
  mEngine.play_black(4, 2);
  mEngine.play_white(3, 0);
  mEngine.play_black(5, 0);
  mEngine.play_white(3, 1);
  mEngine.play_black(5, 2);
  mEngine.play_white(4, 1);
  mEngine.play_black(6, 0);
  mEngine.play_white(5, 1);
  mEngine.play_black(6, 2);
  mEngine.play_white(6, 1);
  mEngine.play_black(7, 1);
  mEngine.play_white(7, 2);
  mEngine.play_black_pass();
  mEngine.play_white(8, 1);

  ASSERT_EQ(mEngine.board().get(1, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::white);

  ASSERT_EQ(mEngine.board().get(2, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);

  ASSERT_EQ(mEngine.board().get(3, 0), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::black);

  ASSERT_EQ(mEngine.board().get(4, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::black);

  ASSERT_EQ(mEngine.board().get(5, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(5, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(5, 2), Stone::black);

  ASSERT_EQ(mEngine.board().get(6, 0), Stone::black);
  ASSERT_EQ(mEngine.board().get(6, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(6, 2), Stone::black);

  ASSERT_EQ(mEngine.board().get(7, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(7, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(7, 2), Stone::white);

  ASSERT_EQ(mEngine.board().get(8, 0), Stone::empty);
  ASSERT_EQ(mEngine.board().get(8, 1), Stone::white);
  ASSERT_EQ(mEngine.board().get(8, 2), Stone::empty);

  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(2, 0);

  EXPECT_EQ(mEngine.board().get(1, 0), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::white);

  EXPECT_EQ(mEngine.board().get(2, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::white);

  EXPECT_EQ(mEngine.board().get(3, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::black);

  EXPECT_EQ(mEngine.board().get(4, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::black);

  EXPECT_EQ(mEngine.board().get(5, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(5, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(5, 2), Stone::black);

  EXPECT_EQ(mEngine.board().get(6, 0), Stone::black);
  EXPECT_EQ(mEngine.board().get(6, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(6, 2), Stone::black);

  EXPECT_EQ(mEngine.board().get(7, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(7, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(7, 2), Stone::white);

  EXPECT_EQ(mEngine.board().get(8, 0), Stone::empty);
  EXPECT_EQ(mEngine.board().get(8, 1), Stone::white);
  EXPECT_EQ(mEngine.board().get(8, 2), Stone::empty);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{5, 0}));
}

TEST_F(GameEngineVerification, capture_pattern9) {

  mEngine.play_black(1, 1);
  mEngine.play_white(2, 2);
  mEngine.play_black(1, 2);
  mEngine.play_white(2, 3);
  mEngine.play_black(1, 3);
  mEngine.play_white(2, 5);
  mEngine.play_black(2, 1);
  mEngine.play_white(3, 2);
  mEngine.play_black(2, 4);
  mEngine.play_white(3, 4);
  mEngine.play_black(3, 1);
  mEngine.play_white(4, 2);
  mEngine.play_black(3, 5);
  mEngine.play_white(4, 3);
  mEngine.play_black(4, 1);
  mEngine.play_white(4, 4);
  mEngine.play_black(4, 5);
  mEngine.play_white(5, 5);
  mEngine.play_black(5, 2);
  mEngine.play_white_pass();
  mEngine.play_black(5, 3);
  mEngine.play_white_pass();
  mEngine.play_black(5, 4);
  mEngine.play_white_pass();

  ASSERT_EQ(mEngine.board().get(1, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(1, 4), Stone::empty);
  ASSERT_EQ(mEngine.board().get(1, 5), Stone::empty);

  ASSERT_EQ(mEngine.board().get(2, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(2, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(2, 5), Stone::white);

  ASSERT_EQ(mEngine.board().get(3, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(3, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 3), Stone::empty);
  ASSERT_EQ(mEngine.board().get(3, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(3, 5), Stone::black);

  ASSERT_EQ(mEngine.board().get(4, 1), Stone::black);
  ASSERT_EQ(mEngine.board().get(4, 2), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 3), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 4), Stone::white);
  ASSERT_EQ(mEngine.board().get(4, 5), Stone::black);

  ASSERT_EQ(mEngine.board().get(5, 1), Stone::empty);
  ASSERT_EQ(mEngine.board().get(5, 2), Stone::black);
  ASSERT_EQ(mEngine.board().get(5, 3), Stone::black);
  ASSERT_EQ(mEngine.board().get(5, 4), Stone::black);
  ASSERT_EQ(mEngine.board().get(5, 5), Stone::white);

  ASSERT_EQ(mEngine.prisoners(), Prisoners{});

  mEngine.play_black(3, 3);

  EXPECT_EQ(mEngine.board().get(1, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(1, 4), Stone::empty);
  EXPECT_EQ(mEngine.board().get(1, 5), Stone::empty);

  EXPECT_EQ(mEngine.board().get(2, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 3), Stone::empty);
  EXPECT_EQ(mEngine.board().get(2, 4), Stone::black);
  EXPECT_EQ(mEngine.board().get(2, 5), Stone::white);

  EXPECT_EQ(mEngine.board().get(3, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(3, 4), Stone::empty);
  EXPECT_EQ(mEngine.board().get(3, 5), Stone::black);

  EXPECT_EQ(mEngine.board().get(4, 1), Stone::black);
  EXPECT_EQ(mEngine.board().get(4, 2), Stone::empty);
  EXPECT_EQ(mEngine.board().get(4, 3), Stone::empty);
  EXPECT_EQ(mEngine.board().get(4, 4), Stone::empty);
  EXPECT_EQ(mEngine.board().get(4, 5), Stone::black);

  EXPECT_EQ(mEngine.board().get(5, 1), Stone::empty);
  EXPECT_EQ(mEngine.board().get(5, 2), Stone::black);
  EXPECT_EQ(mEngine.board().get(5, 3), Stone::black);
  EXPECT_EQ(mEngine.board().get(5, 4), Stone::black);
  EXPECT_EQ(mEngine.board().get(5, 5), Stone::white);

  EXPECT_EQ(mEngine.prisoners(), (Prisoners{7, 0}));
}
