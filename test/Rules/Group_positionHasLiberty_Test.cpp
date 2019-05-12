#include "Group.h"

#include "TwoDimensionArrayBoard.h"
#include "Util/BoardTransformation.h"
#include "gtest/gtest.h"

namespace {

TEST(position_has_liberty, out_of_bounds) {
  Go::TwoDimensionArrayBoard<1, 1> board{};

  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 0, 0));

  board.set(0, 0, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 0, 0));
  board.set(0, 0, Go::Stone::white);
  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 0, 0));
}

TEST(position_has_liberty, 4_liberty) {
  Go::TwoDimensionArrayBoard<3, 3> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);
  board.set(0, 1, Go::Stone::white);
  board.set(2, 0, Go::Stone::white);

  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));
}

TEST(position_has_liberty, 3_liberty) {
  Go::TwoDimensionArrayBoard<3, 3> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);
  board.set(0, 1, Go::Stone::white);
  board.set(2, 0, Go::Stone::white);
  board.set(0, 1, Go::Stone::black);

  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));
}

TEST(position_has_liberty, 2_liberty) {
  Go::TwoDimensionArrayBoard<3, 3> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);
  board.set(0, 1, Go::Stone::white);
  board.set(2, 0, Go::Stone::white);

  board.set(0, 1, Go::Stone::black);
  board.set(2, 1, Go::Stone::white);

  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));
}

TEST(position_has_liberty, 1_liberty) {
  Go::TwoDimensionArrayBoard<3, 3> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);
  board.set(0, 1, Go::Stone::white);
  board.set(2, 0, Go::Stone::white);

  board.set(0, 1, Go::Stone::black);
  board.set(1, 0, Go::Stone::black);
  board.set(2, 1, Go::Stone::white);

  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::position_has_liberty(board, 1, 1));
}

TEST(position_has_liberty, 0_liberty) {
  Go::TwoDimensionArrayBoard<3, 3> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);
  board.set(0, 1, Go::Stone::white);
  board.set(2, 0, Go::Stone::white);

  board.set(0, 1, Go::Stone::black);
  board.set(1, 0, Go::Stone::black);
  board.set(2, 1, Go::Stone::white);
  board.set(1, 2, Go::Stone::white);

  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 1, 1));

  board = Go::Util::rotate(board);
  EXPECT_FALSE(Go::Rules::Group::position_has_liberty(board, 1, 1));
}
} // namespace
