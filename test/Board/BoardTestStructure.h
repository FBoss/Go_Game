#ifndef BOARDTESTSTRUCTURE_H
#define BOARDTESTSTRUCTURE_H

#include "gtest/gtest.h"

#include "Dimension.h"
#include "Stone.h"

#include <random>
#include <stdexcept>
#include <type_traits>

//#include <iostream>

namespace {

template <typename T> class BoardTest : public ::testing::Test {

protected:
  void SetUp() override { mBoard = T{}; }
  void TearDown() override {}

public:
  T mBoard;

  void randomizeBoard() {

    Go::Dimension dim = this->mBoard.getDimension();

    std::mt19937 row_generator(0);
    std::mt19937 column_generator(1);
    std::mt19937 stone_generator(3);

    std::uniform_int_distribution<unsigned int> row_distribution(0, dim.row - 1);
    std::uniform_int_distribution<unsigned int> column_distribution(0, dim.column - 1);
    std::uniform_int_distribution<unsigned int> stone_distribution(0, 3);

    for (unsigned int i = 0; i < dim.row * dim.column; ++i) {
      auto row = static_cast<unsigned int>(row_distribution(row_generator));
      auto column = static_cast<unsigned int>(column_distribution(column_generator));
      auto stone = static_cast<Go::Stone>(stone_distribution(stone_generator));

      mBoard.set(row, column, stone);
    }
  }
};

TYPED_TEST_CASE_P(BoardTest);

TYPED_TEST_P(BoardTest, DefaultValue) {
  Go::Dimension dim = this->mBoard.getDimension();
  volatile Go::Stone stone;

  for (volatile unsigned int row = 0; row < dim.row; ++row) {
    for (volatile unsigned int column = 0; column < dim.column; ++column) {
      stone = this->mBoard.get(row, column);
      EXPECT_EQ(static_cast<int>(Go::Stone::empty), static_cast<int>(stone));
    }
  }
  /*
  for(unsigned int row=0; row < dim.row; ++row)
  {
    for(unsigned int column=0; column < dim.column; ++column)
    {
      std::cout << static_cast<int>(stone);
    }
    std::cout << '\n';
  }
*/
}

TYPED_TEST_P(BoardTest, GetOutOfRangeNegative) {
  Go::Dimension dim = this->mBoard.getDimension();

  EXPECT_THROW(this->mBoard.get(-1, 0), std::out_of_range);
  EXPECT_THROW(this->mBoard.get(0, -1), std::out_of_range);
  EXPECT_THROW(this->mBoard.get(-1, -1), std::out_of_range);
}

TYPED_TEST_P(BoardTest, GetOutOfRangePositive) {
  Go::Dimension dim = this->mBoard.getDimension();

  EXPECT_THROW(this->mBoard.get(dim.row, 0), std::out_of_range);
  EXPECT_THROW(this->mBoard.get(0, dim.column), std::out_of_range);
  EXPECT_THROW(this->mBoard.get(dim.row, dim.column), std::out_of_range);
}

TYPED_TEST_P(BoardTest, SetOutOfRangePositive) {
  Go::Dimension dim = this->mBoard.getDimension();

  EXPECT_THROW(this->mBoard.set(dim.row, 0, Go::Stone::empty), std::out_of_range);
  EXPECT_THROW(this->mBoard.set(0, dim.column, Go::Stone::empty), std::out_of_range);
  EXPECT_THROW(this->mBoard.set(dim.row, dim.column, Go::Stone::empty), std::out_of_range);
}

TYPED_TEST_P(BoardTest, SetOutOfRangeNegative) {
  Go::Dimension dim = this->mBoard.getDimension();

  EXPECT_THROW(this->mBoard.set(-1, 0, Go::Stone::empty), std::out_of_range);
  EXPECT_THROW(this->mBoard.set(0, -1, Go::Stone::empty), std::out_of_range);
  EXPECT_THROW(this->mBoard.set(-1, -1, Go::Stone::empty), std::out_of_range);
}

TYPED_TEST_P(BoardTest, RandomReadWrite) {
  Go::Dimension dim = this->mBoard.getDimension();

  std::mt19937 row_generator(0);
  std::mt19937 column_generator(1);
  std::mt19937 stone_generator(3);

  std::uniform_int_distribution<unsigned int> row_distribution(0, dim.row - 1);
  std::uniform_int_distribution<unsigned int> column_distribution(0, dim.column - 1);
  std::uniform_int_distribution<unsigned int> stone_distribution(0, 3);

  for (volatile unsigned int i = 0; i < dim.row * dim.column * 100; ++i) {
    auto row = static_cast<unsigned int>(row_distribution(row_generator));
    auto column = static_cast<unsigned int>(column_distribution(column_generator));
    auto stone = static_cast<Go::Stone>(stone_distribution(stone_generator));

    this->mBoard.set(row, column, stone);
    EXPECT_EQ(stone, this->mBoard.get(row, column));
  }
}

TYPED_TEST_P(BoardTest, EqualOperatorDefaultConstructible) {
  decltype(this->mBoard) board1{};
  decltype(this->mBoard) board2{};

  EXPECT_TRUE(board1 == board2);
}

TYPED_TEST_P(BoardTest, EqualOperator) {
  decltype(this->mBoard) board1{};
  decltype(this->mBoard) board2{};

  Go::Dimension dim = board1.getDimension();

  for (volatile unsigned int i = 0; i < dim.row; ++i) {
    for (volatile unsigned int j = 0; j < dim.column; ++j) {
      board1.set(i, j, Go::Stone::black);
      EXPECT_FALSE(board1 == board2);
      board1.set(i, j, Go::Stone::empty);
    }
  }
}

TYPED_TEST_P(BoardTest, NotEqualOperatorDefaultConstructible) {
  decltype(this->mBoard) board1{};
  decltype(this->mBoard) board2{};

  EXPECT_FALSE(board1 != board2);
}

TYPED_TEST_P(BoardTest, NotEqualOperator) {
  decltype(this->mBoard) board1{};
  decltype(this->mBoard) board2{};

  Go::Dimension dim = board1.getDimension();

  for (volatile unsigned int i = 0; i < dim.row; ++i) {
    for (volatile unsigned int j = 0; j < dim.column; ++j) {
      board1.set(i, j, Go::Stone::black);
      EXPECT_TRUE(board1 != board2);
      board1.set(i, j, Go::Stone::empty);
    }
  }
}

TYPED_TEST_P(BoardTest, DefaultConstructible) { EXPECT_TRUE(std::is_default_constructible<decltype(this->mBoard)>::value); }
TYPED_TEST_P(BoardTest, MoveConstructible) {
  EXPECT_TRUE(std::is_move_constructible<decltype(this->mBoard)>::value);

  decltype(this->mBoard) board1{}, excpected_board{};

  Go::Dimension dim = board1.getDimension();
  if (dim.row > 0 && dim.column > 0) {
    board1.set(0, 0, Go::Stone::black);
    excpected_board.set(0, 0, Go::Stone::black);
  }

  decltype(this->mBoard) board2 = std::move(board1);

  EXPECT_EQ(excpected_board, board2);
}

TYPED_TEST_P(BoardTest, MoveAssignable) {
  EXPECT_TRUE(std::is_move_assignable<decltype(this->mBoard)>::value);

  decltype(this->mBoard) board1{}, board2{}, excpected_board{};

  Go::Dimension dim = board1.getDimension();
  if (dim.row > 0 && dim.column > 0) {
    board1.set(0, 0, Go::Stone::black);
    excpected_board.set(0, 0, Go::Stone::black);
  }

  board2 = std::move(board1);

  EXPECT_EQ(excpected_board, board2);
}

TYPED_TEST_P(BoardTest, Destructible) { EXPECT_TRUE(std::is_destructible<decltype(this->mBoard)>::value); }

TYPED_TEST_P(BoardTest, CopyConstructible) {
  EXPECT_TRUE(std::is_copy_constructible<decltype(this->mBoard)>::value);

  decltype(this->mBoard) board1{};

  Go::Dimension dim = board1.getDimension();
  if (dim.row > 0 && dim.column > 0) {
    board1.set(0, 0, Go::Stone::black);
  }

  decltype(this->mBoard) board2 = board1;

  EXPECT_EQ(board1, board2);
}

TYPED_TEST_P(BoardTest, CopyAssignable) {
  EXPECT_TRUE(std::is_copy_assignable<decltype(this->mBoard)>::value);

  decltype(this->mBoard) board1{}, board2{};

  Go::Dimension dim = board1.getDimension();
  if (dim.row > 0 && dim.column > 0) {
    board1.set(0, 0, Go::Stone::black);
  }

  board2 = board1;

  EXPECT_EQ(board1, board2);
}

REGISTER_TYPED_TEST_CASE_P(BoardTest, // The first argument is the test case name.
                                      // The rest of the arguments are the test names.
                           DefaultValue, GetOutOfRangeNegative, GetOutOfRangePositive, SetOutOfRangeNegative, SetOutOfRangePositive,
                           RandomReadWrite,

                           DefaultConstructible, EqualOperatorDefaultConstructible, EqualOperator, NotEqualOperatorDefaultConstructible,
                           NotEqualOperator, MoveConstructible, MoveAssignable, Destructible, CopyConstructible, CopyAssignable);

} // namespace

#endif // BOARDTESTSTRUCTURE_H
