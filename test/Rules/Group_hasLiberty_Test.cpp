#include "Group.h"

#include "TwoDimensionArrayBoard.h"
#include "Util/BoardTransformation.h"
#include "gtest/gtest.h"

namespace {

constexpr auto board1() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::white);
  board.set(0, 2, Go::Stone::empty);
  board.set(0, 3, Go::Stone::white);

  board.set(1, 0, Go::Stone::white);
  board.set(1, 1, Go::Stone::empty);
  board.set(1, 2, Go::Stone::empty);
  board.set(1, 3, Go::Stone::empty);

  board.set(2, 0, Go::Stone::black);
  board.set(2, 1, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);
  board.set(2, 3, Go::Stone::empty);

  board.set(3, 0, Go::Stone::empty);
  board.set(3, 1, Go::Stone::empty);
  board.set(3, 2, Go::Stone::white);
  board.set(3, 3, Go::Stone::black);

  return board;
}

constexpr auto board2() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::empty);
  board.set(0, 2, Go::Stone::empty);
  board.set(0, 3, Go::Stone::empty);

  board.set(1, 0, Go::Stone::empty);
  board.set(1, 1, Go::Stone::empty);
  board.set(1, 2, Go::Stone::white);
  board.set(1, 3, Go::Stone::white);

  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::white);
  board.set(2, 2, Go::Stone::black);
  board.set(2, 3, Go::Stone::black);

  board.set(3, 0, Go::Stone::empty);
  board.set(3, 1, Go::Stone::white);
  board.set(3, 2, Go::Stone::black);
  board.set(3, 3, Go::Stone::black);

  return board;
}

constexpr auto board3() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::empty);
  board.set(0, 2, Go::Stone::empty);
  board.set(0, 3, Go::Stone::empty);

  board.set(1, 0, Go::Stone::empty);
  board.set(1, 1, Go::Stone::empty);
  board.set(1, 2, Go::Stone::white);
  board.set(1, 3, Go::Stone::white);

  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::white);
  board.set(2, 2, Go::Stone::black);
  board.set(2, 3, Go::Stone::black);

  board.set(3, 0, Go::Stone::empty);
  board.set(3, 1, Go::Stone::empty);
  board.set(3, 2, Go::Stone::black);
  board.set(3, 3, Go::Stone::black);

  return board;
}

constexpr auto board4() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::white);
  board.set(0, 1, Go::Stone::white);
  board.set(0, 2, Go::Stone::black);
  board.set(0, 3, Go::Stone::white);

  board.set(1, 0, Go::Stone::black);
  board.set(1, 1, Go::Stone::black);
  board.set(1, 2, Go::Stone::black);
  board.set(1, 3, Go::Stone::white);

  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::white);
  board.set(2, 2, Go::Stone::black);
  board.set(2, 3, Go::Stone::white);

  board.set(3, 0, Go::Stone::white);
  board.set(3, 1, Go::Stone::black);
  board.set(3, 2, Go::Stone::black);
  board.set(3, 3, Go::Stone::white);

  return board;
}

TEST(group_has_liberty, 1x1_board_empty) {
  Go::TwoDimensionArrayBoard<1, 1> board{};
  board.set(0, 0, Go::Stone::empty);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
}

TEST(group_has_liberty, 1x1_board_color_match) {
  Go::TwoDimensionArrayBoard<1, 1> board{};
  board.set(0, 0, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  board.set(0, 0, Go::Stone::white);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
}

TEST(group_has_liberty, 1x1_board_color_differ) {
  Go::TwoDimensionArrayBoard<1, 1> board{};
  board.set(0, 0, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  board.set(0, 0, Go::Stone::white);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
}

TEST(group_has_liberty, 1x2board_liberty) {
  Go::TwoDimensionArrayBoard<1, 2> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::empty);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::white);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::empty);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
}

TEST(group_has_liberty, 1x2board_no_liberty) {
  Go::TwoDimensionArrayBoard<1, 2> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  board.set(0, 0, Go::Stone::white);
  board.set(0, 1, Go::Stone::white);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 1)());

  board.set(0, 0, Go::Stone::white);
  board.set(0, 1, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
}

TEST(group_has_liberty, 2x1board_no_liberty) {
  Go::TwoDimensionArrayBoard<2, 1> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(1, 0, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  board.set(0, 0, Go::Stone::white);
  board.set(1, 0, Go::Stone::white);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 1, 0)());

  board.set(0, 0, Go::Stone::white);
  board.set(1, 0, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 1, 0)());
}

TEST(group_has_liberty, 2x2_empty) {
  Go::TwoDimensionArrayBoard<2, 2> board{};

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 1)());
}

TEST(group_has_liberty, 2x2_1point) {
  Go::TwoDimensionArrayBoard<2, 2> board{};
  board.set(0, 0, Go::Stone::black);

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(board), 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(board)), 1, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(Go::Util::rotate(board))), 1, 1)());

  board = Go::Util::invert(board);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(board), 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(board)), 1, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(Go::Util::rotate(board))), 1, 0)());
}

TEST(group_has_liberty, 2x2_2points) {
  Go::TwoDimensionArrayBoard<2, 2> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::black);

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(board), 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(board)), 1, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(Go::Util::rotate(board))), 1, 0)());

  board = Go::Util::invert(board);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(board), 1, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(board)), 1, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::rotate(Go::Util::rotate(Go::Util::rotate(board))), 0, 0)());
}

TEST(group_has_liberty, loop) {
  Go::TwoDimensionArrayBoard<3, 3> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::black);
  board.set(0, 2, Go::Stone::black);
  board.set(1, 0, Go::Stone::black);
  board.set(1, 2, Go::Stone::black);
  board.set(2, 0, Go::Stone::black);
  board.set(2, 1, Go::Stone::black);
  board.set(2, 2, Go::Stone::black);

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board), 0, 0)());

  board.set(1, 1, Go::Stone::white);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 2, 2)());
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board), 2, 2)());

  board.set(1, 1, Go::Stone::black);
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board, 2, 2)());
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board), 2, 2)());
}

TEST(group_has_liberty, 2x2_3points_same_color) {
  Go::TwoDimensionArrayBoard<2, 2> board{};
  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::black);
  board.set(1, 1, Go::Stone::black);

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 1)());

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 0)());

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 0)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 0)());

  board = Go::Util::rotate(board);
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 0, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board, 1, 0)());
}

TEST(group_has_liberty, scenario1) {
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board1(), 0, 0)());
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board1()), 0, 0)());

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board1(), 0, 3)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board1()), 0, 3)());

  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board1(), 2, 1)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board1()), 2, 1)());
}

TEST(group_has_liberty, scenario2) {
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board2(), 2, 3)());
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board2()), 2, 3)());
}

TEST(group_has_liberty, scenario3) {
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board3(), 2, 3)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board3()), 2, 3)());
}

TEST(group_has_liberty, scenario4) {
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(board4(), 2, 2)());
  EXPECT_TRUE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board4()), 2, 2)());

  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(board4(), 0, 3)());
  EXPECT_FALSE(Go::Rules::Group::group_has_liberty(Go::Util::invert(board4()), 0, 3)());
}

} // namespace
