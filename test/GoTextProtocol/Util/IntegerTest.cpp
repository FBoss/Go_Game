#include "gtest/gtest.h"

#include "Integer.h"

using namespace Go::GoTextProtocol::Util;

namespace {

TEST(isDigit, digits) {
  EXPECT_TRUE(isDigit('0'));
  EXPECT_TRUE(isDigit('1'));
  EXPECT_TRUE(isDigit('2'));
  EXPECT_TRUE(isDigit('3'));
  EXPECT_TRUE(isDigit('4'));
  EXPECT_TRUE(isDigit('5'));
  EXPECT_TRUE(isDigit('6'));
  EXPECT_TRUE(isDigit('7'));
  EXPECT_TRUE(isDigit('8'));
  EXPECT_TRUE(isDigit('9'));
}

TEST(isDigit, non_digits) {
  for (char character = 0; character < '0'; ++character) {
    EXPECT_FALSE(isDigit(character));
  }
  for (char character = '9' + 1; character < 127; ++character) {
    EXPECT_FALSE(isDigit(character));
  }
  EXPECT_FALSE(isDigit(127));
}

TEST(isInteger, empty) { EXPECT_FALSE(isInteger("")); }

TEST(isInteger, zero) { EXPECT_TRUE(isInteger("0")); }

TEST(isInteger, numer) { EXPECT_TRUE(isInteger("0230460")); }

TEST(isInteger, word) { EXPECT_FALSE(isInteger("word")); }

TEST(isInteger, word_int_mixed) { EXPECT_FALSE(isInteger("0870word435")); }

} // namespace
