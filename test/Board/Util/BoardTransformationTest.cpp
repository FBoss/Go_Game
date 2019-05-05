#include "Util/BoardTransformation.h"
#include "TwoDimensionArrayBoard.h"

#include "gtest/gtest.h"

namespace {

constexpr auto board_3x3() noexcept {
  Go::TwoDimensionArrayBoard<3, 3> board{};

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::white);
  board.set(0, 2, Go::Stone::black);
  board.set(1, 0, Go::Stone::white);
  board.set(1, 1, Go::Stone::black);
  board.set(1, 2, Go::Stone::empty);
  board.set(2, 0, Go::Stone::white);
  board.set(2, 1, Go::Stone::black);
  board.set(2, 2, Go::Stone::empty);

  return board;
}

constexpr auto board_3x3_90() noexcept {
  Go::TwoDimensionArrayBoard<3, 3> board{};

  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::empty);
  board.set(0, 2, Go::Stone::empty);
  board.set(1, 0, Go::Stone::white);
  board.set(1, 1, Go::Stone::black);
  board.set(1, 2, Go::Stone::black);
  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::white);
  board.set(2, 2, Go::Stone::white);

  return board;
}

constexpr auto board_3x3_180() noexcept {
  Go::TwoDimensionArrayBoard<3, 3> board{};

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::black);
  board.set(0, 2, Go::Stone::white);
  board.set(1, 0, Go::Stone::empty);
  board.set(1, 1, Go::Stone::black);
  board.set(1, 2, Go::Stone::white);
  board.set(2, 0, Go::Stone::black);
  board.set(2, 1, Go::Stone::white);
  board.set(2, 2, Go::Stone::empty);

  return board;
}

constexpr auto board_3x3_270() noexcept {
  Go::TwoDimensionArrayBoard<3, 3> board{};

  board.set(0, 0, Go::Stone::white);
  board.set(0, 1, Go::Stone::white);
  board.set(0, 2, Go::Stone::empty);
  board.set(1, 0, Go::Stone::black);
  board.set(1, 1, Go::Stone::black);
  board.set(1, 2, Go::Stone::white);
  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::empty);
  board.set(2, 2, Go::Stone::black);

  return board;
}

constexpr auto board_4x4() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::white);
  board.set(0, 2, Go::Stone::empty);
  board.set(0, 3, Go::Stone::white);
  board.set(1, 0, Go::Stone::empty);
  board.set(1, 1, Go::Stone::empty);
  board.set(1, 2, Go::Stone::black);
  board.set(1, 3, Go::Stone::empty);
  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::white);
  board.set(2, 2, Go::Stone::empty);
  board.set(2, 3, Go::Stone::black);
  board.set(3, 0, Go::Stone::black);
  board.set(3, 1, Go::Stone::empty);
  board.set(3, 2, Go::Stone::empty);
  board.set(3, 3, Go::Stone::empty);

  return board;
}

constexpr auto board_4x4_90() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::white);
  board.set(0, 1, Go::Stone::empty);
  board.set(0, 2, Go::Stone::black);
  board.set(0, 3, Go::Stone::empty);
  board.set(1, 0, Go::Stone::empty);
  board.set(1, 1, Go::Stone::black);
  board.set(1, 2, Go::Stone::empty);
  board.set(1, 3, Go::Stone::empty);
  board.set(2, 0, Go::Stone::white);
  board.set(2, 1, Go::Stone::empty);
  board.set(2, 2, Go::Stone::white);
  board.set(2, 3, Go::Stone::empty);
  board.set(3, 0, Go::Stone::empty);
  board.set(3, 1, Go::Stone::empty);
  board.set(3, 2, Go::Stone::empty);
  board.set(3, 3, Go::Stone::black);

  return board;
}

constexpr auto board_4x4_180() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::empty);
  board.set(0, 1, Go::Stone::empty);
  board.set(0, 2, Go::Stone::empty);
  board.set(0, 3, Go::Stone::black);
  board.set(1, 0, Go::Stone::black);
  board.set(1, 1, Go::Stone::empty);
  board.set(1, 2, Go::Stone::white);
  board.set(1, 3, Go::Stone::empty);
  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::black);
  board.set(2, 2, Go::Stone::empty);
  board.set(2, 3, Go::Stone::empty);
  board.set(3, 0, Go::Stone::white);
  board.set(3, 1, Go::Stone::empty);
  board.set(3, 2, Go::Stone::white);
  board.set(3, 3, Go::Stone::empty);

  return board;
}

constexpr auto board_4x4_270() noexcept {
  Go::TwoDimensionArrayBoard<4, 4> board{};

  board.set(0, 0, Go::Stone::black);
  board.set(0, 1, Go::Stone::empty);
  board.set(0, 2, Go::Stone::empty);
  board.set(0, 3, Go::Stone::empty);
  board.set(1, 0, Go::Stone::empty);
  board.set(1, 1, Go::Stone::white);
  board.set(1, 2, Go::Stone::empty);
  board.set(1, 3, Go::Stone::white);
  board.set(2, 0, Go::Stone::empty);
  board.set(2, 1, Go::Stone::empty);
  board.set(2, 2, Go::Stone::black);
  board.set(2, 3, Go::Stone::empty);
  board.set(3, 0, Go::Stone::empty);
  board.set(3, 1, Go::Stone::black);
  board.set(3, 2, Go::Stone::empty);
  board.set(3, 3, Go::Stone::white);

  return board;
}

TEST(BoardTransformationTest, emptyBoard) {
  Go::TwoDimensionArrayBoard<3, 3> begin{};
  auto rot = Go::Util::rotate(begin);
  EXPECT_EQ(begin, rot);
    }

    TEST(BoardTransformationTest, 3x3_90) {
      constexpr auto rot = Go::Util::rotate(board_3x3());
      EXPECT_EQ(board_3x3_90(), rot);
    }

    TEST(BoardTransformationTest, 3x3_180) {
      constexpr auto rot = []() {
        auto val = Go::Util::rotate(board_3x3());
        return Go::Util::rotate(val);
      }();
      EXPECT_EQ(board_3x3_180(), rot);
    }

    TEST(BoardTransformationTest, 3x3_270) {
      constexpr auto rot = []() {
        auto val = Go::Util::rotate(board_3x3());

        val = Go::Util::rotate(val);
        return Go::Util::rotate(val);
      }();
      EXPECT_EQ(board_3x3_270(), rot);
    }

    TEST(BoardTransformationTest, 3x3_360) {
      constexpr auto rot = []() {
        auto val = Go::Util::rotate(board_3x3());

        val = Go::Util::rotate(val);
        val = Go::Util::rotate(val);
        return Go::Util::rotate(val);
      }();
      EXPECT_EQ(board_3x3(), rot);
    }

    TEST(BoardTransformationTest, 4x4_90) {
      constexpr auto rot = Go::Util::rotate(board_4x4());
      EXPECT_EQ(board_4x4_90(), rot);
    }

    TEST(BoardTransformationTest, 4x4_180) {
      constexpr auto rot = []() {
        auto val = Go::Util::rotate(board_4x4());
        return Go::Util::rotate(val);
      }();

      EXPECT_EQ(board_4x4_180(), rot);
    }

    TEST(BoardTransformationTest, 4x4_270) {
      constexpr auto rot = []() {
        auto val = Go::Util::rotate(board_4x4());
        val = Go::Util::rotate(val);
        return Go::Util::rotate(val);
      }();
      EXPECT_EQ(board_4x4_270(), rot);
    }

    TEST(BoardTransformationTest, 4x4_360) {
      constexpr auto rot = []() {
        auto val = Go::Util::rotate(board_4x4());

        val = Go::Util::rotate(val);
        val = Go::Util::rotate(val);
        return Go::Util::rotate(val);
      }();
      EXPECT_EQ(board_4x4(), rot);
    }

} // namespace