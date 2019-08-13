#include "gtest/gtest.h"

#include "TwoDimensionArrayBoard.h"
#include "territory_scoring.h"

namespace {
TEST(territory_scoring, empty_board) {
  auto score = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score.black, 0);
  EXPECT_EQ(score.white, 0);
  EXPECT_EQ(score.empty, 9);
}

TEST(territory_scoring, single_center_point) {
  auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(1, 1, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 8);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 1);

  auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(1, 1, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 8);
  EXPECT_EQ(score_white.empty, 1);
}

TEST(territory_scoring, single_border_point) {
  auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 1, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 8);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 1);

  auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(1, 2, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 8);
  EXPECT_EQ(score_white.empty, 1);
}

TEST(territory_scoring, single_corner_point) {
  auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 0, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 8);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 1);

  auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 2, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 8);
  EXPECT_EQ(score_white.empty, 1);
}

TEST(territory_scoring, two_point) {
  auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 0, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 8);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 1);

  auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 2, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 8);
  EXPECT_EQ(score_white.empty, 1);
}

TEST(territory_scoring, half_single_point) {
  auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(1, 0, Go::Stone::black);
    board.set(1, 1, Go::Stone::black);
    board.set(1, 2, Go::Stone::black);
    board.set(0, 0, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 3);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 6);

  constexpr auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 1, Go::Stone::white);
    board.set(1, 1, Go::Stone::white);
    board.set(2, 1, Go::Stone::white);
    board.set(2, 2, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 3);
  EXPECT_EQ(score_white.empty, 6);
}

TEST(territory_scoring, full_surounded_point) {
  constexpr auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 0, Go::Stone::black);
    board.set(0, 1, Go::Stone::black);
    board.set(0, 2, Go::Stone::black);
    board.set(1, 0, Go::Stone::black);
    board.set(1, 2, Go::Stone::black);
    board.set(2, 0, Go::Stone::black);
    board.set(2, 1, Go::Stone::black);
    board.set(2, 2, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 1);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 8);

  constexpr auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 0, Go::Stone::white);
    board.set(0, 1, Go::Stone::white);
    board.set(0, 2, Go::Stone::white);
    board.set(1, 0, Go::Stone::white);
    board.set(1, 1, Go::Stone::black);
    board.set(1, 2, Go::Stone::white);
    board.set(2, 0, Go::Stone::white);
    board.set(2, 1, Go::Stone::white);
    board.set(2, 2, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 0);
  EXPECT_EQ(score_white.empty, 9);
}

TEST(territory_scoring, partial_surounded_point) {
  constexpr auto score_black = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 1, Go::Stone::black);
    board.set(1, 1, Go::Stone::black);
    board.set(1, 0, Go::Stone::black);
    board.set(2, 2, Go::Stone::white);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_black.black, 1);
  EXPECT_EQ(score_black.white, 0);
  EXPECT_EQ(score_black.empty, 8);

  constexpr auto score_white = []() {
    Go::TwoDimensionArrayBoard<3, 3> board{};
    board.set(0, 0, Go::Stone::white);
    board.set(0, 1, Go::Stone::white);
    board.set(1, 1, Go::Stone::white);
    board.set(2, 1, Go::Stone::white);
    board.set(2, 0, Go::Stone::white);
    board.set(1, 2, Go::Stone::black);
    return Go::Rules::score_territory(board);
  }();
  EXPECT_EQ(score_white.black, 0);
  EXPECT_EQ(score_white.white, 1);
  EXPECT_EQ(score_white.empty, 8);
}
} // namespace
