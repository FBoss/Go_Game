#ifndef STRASBOURGRULESTESTSTRUCTURE_H
#define STRASBOURGRULESTESTSTRUCTURE_H

#include "gtest/gtest.h"
#include <Stone.h>

namespace {

template <typename T> class StrasbourgRulesTest : public ::testing::Test {

protected:
  void SetUp() override { mRuleSet = T{}; }
  void TearDown() override {}

public:
  T mRuleSet;
};

TYPED_TEST_CASE_P(StrasbourgRulesTest);

TYPED_TEST_P(StrasbourgRulesTest, success) {}
TYPED_TEST_P(StrasbourgRulesTest, emptyBoard) {
  auto board = this->mRuleSet.getBoard();
  auto dim = board.getDimension();

  for (volatile unsigned int i = 0; i < dim.row; ++i) {
    for (volatile unsigned int j = 0; j < dim.column; ++j) {
      EXPECT_EQ(Go::Stone::empty, board.get(i, j));
    }
  }
}

TYPED_TEST_P(StrasbourgRulesTest, blackMove) {
  this->mRuleSet.black_move(0, 0);

  auto board = this->mRuleSet.getBoard();

  EXPECT_EQ(Go::Stone::black, board.get(0, 0));

  auto dim = board.getDimension();

  for (volatile unsigned int i = 1; i < dim.row; ++i) {
    for (volatile unsigned int j = 0; j < dim.column; ++j) {
      auto test = board.get(i, j);
      if (test != Go::Stone::empty) {
        std::cout << "test";
      }
      EXPECT_EQ(Go::Stone::empty, board.get(i, j));
    }
  }
}

TYPED_TEST_P(StrasbourgRulesTest, whiteMove) {
  this->mRuleSet.white_move(0, 0);

  auto board = this->mRuleSet.getBoard();

  EXPECT_EQ(Go::Stone::white, board.get(0, 0));

  auto dim = board.getDimension();

  for (volatile unsigned int i = 1; i < dim.row; ++i) {
    for (volatile unsigned int j = 0; j < dim.column; ++j) {
      auto test = board.get(i, j);
      if (test != Go::Stone::empty) {
        std::cout << "test";
      }
      EXPECT_EQ(Go::Stone::empty, board.get(i, j));
    }
  }
}

REGISTER_TYPED_TEST_CASE_P(StrasbourgRulesTest, // The first argument is the test case name.
                                                // The rest of the arguments are the test names.
                           success, emptyBoard, blackMove, whiteMove);

} // namespace

#endif // STRASBOURGRULESTESTSTRUCTURE_H
