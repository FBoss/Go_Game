#include "Util/BoardTransformation.h"
#include "TwoDimensionArrayBoard.h"

#include "gtest/gtest.h"

namespace {

    constexpr auto board1() noexcept {
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

    constexpr auto board1_inverse() noexcept {
        Go::TwoDimensionArrayBoard<3, 3> board{};

        board.set(0, 0, Go::Stone::empty);
        board.set(0, 1, Go::Stone::black);
        board.set(0, 2, Go::Stone::white);
        board.set(1, 0, Go::Stone::black);
        board.set(1, 1, Go::Stone::white);
        board.set(1, 2, Go::Stone::empty);
        board.set(2, 0, Go::Stone::black);
        board.set(2, 1, Go::Stone::white);
        board.set(2, 2, Go::Stone::empty);

        return board;
    }


    TEST(BoardInversionTest, inverse) {
        constexpr auto inverse = Go::Util::invert(board1());
        EXPECT_EQ(board1_inverse(), inverse);
    }

} // namespace