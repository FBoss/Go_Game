#include "Group.h"

#include "TwoDimensionArrayBoard.h"
#include "Util/BoardTransformation.h"
#include "gtest/gtest.h"

namespace {

TEST(remove, 1x1_empty) {
  Go::TwoDimensionArrayBoard<1, 1> result{};
  auto expected = result;
  Go::Rules::Group::group_remove(result, Go::Stone::empty, 0, 0);
  EXPECT_EQ(expected, result);

  Go::Rules::Group::group_remove(result, Go::Stone::black, 0, 0);
  EXPECT_EQ(expected, result);

  Go::Rules::Group::group_remove(result, Go::Stone::white, 0, 0);
  EXPECT_EQ(expected, result);
}

TEST(remove, 1x1_black) {
  Go::TwoDimensionArrayBoard<1, 1> result{};
  result.set(0, 0, Go::Stone::black);
  auto expected = result;

  Go::Rules::Group::group_remove(result, Go::Stone::empty, 0, 0);
  EXPECT_EQ(expected, result);

  Go::Rules::Group::group_remove(result, Go::Stone::white, 0, 0);
  EXPECT_EQ(expected, result);

  expected.set(0, 0, Go::Stone::empty);
  Go::Rules::Group::group_remove(result, Go::Stone::black, 0, 0);
  EXPECT_EQ(expected, result);
}

TEST(remove, 1x1_white) {
  Go::TwoDimensionArrayBoard<1, 1> result{};
  result.set(0, 0, Go::Stone::white);
  auto expected = result;

  Go::Rules::Group::group_remove(result, Go::Stone::empty, 0, 0);
  EXPECT_EQ(expected, result);

  Go::Rules::Group::group_remove(result, Go::Stone::black, 0, 0);
  EXPECT_EQ(expected, result);

  expected.set(0, 0, Go::Stone::empty);
  Go::Rules::Group::group_remove(result, Go::Stone::white, 0, 0);
  EXPECT_EQ(expected, result);
}

TEST(remove, 3x3_loop_middle_empty) {
  Go::TwoDimensionArrayBoard<3, 3> result{};
  result.set(0, 0, Go::Stone::black);
  result.set(0, 1, Go::Stone::black);
  result.set(0, 2, Go::Stone::black);
  result.set(1, 0, Go::Stone::black);
  result.set(1, 2, Go::Stone::black);
  result.set(2, 0, Go::Stone::black);
  result.set(2, 1, Go::Stone::black);
  result.set(2, 2, Go::Stone::black);
  auto expected = result;

  Go::Rules::Group::group_remove(result, Go::Stone::empty, 0, 0);
  EXPECT_EQ(expected, result);

  Go::Rules::Group::group_remove(result, Go::Stone::white, 2, 2);
  EXPECT_EQ(expected, result);

  expected = Go::TwoDimensionArrayBoard<3, 3>{};
  Go::Rules::Group::group_remove(result, Go::Stone::black, 0, 1);
  EXPECT_EQ(expected, result);
}

TEST(remove, 3x3_loop_middle_filled) {
  Go::TwoDimensionArrayBoard<3, 3> result{};
  result.set(0, 0, Go::Stone::black);
  result.set(0, 1, Go::Stone::black);
  result.set(0, 2, Go::Stone::black);
  result.set(1, 0, Go::Stone::black);
  result.set(1, 1, Go::Stone::white);
  result.set(1, 2, Go::Stone::black);
  result.set(2, 0, Go::Stone::black);
  result.set(2, 1, Go::Stone::black);
  result.set(2, 2, Go::Stone::black);
  auto expected = result;

  Go::Rules::Group::group_remove(result, Go::Stone::empty, 0, 0);
  ASSERT_EQ(expected, result);

  Go::Rules::Group::group_remove(result, Go::Stone::white, 0, 0);
  ASSERT_EQ(expected, result);

  auto result_invert = Go::Util::invert(result);
  expected = Go::Util::invert(expected);
  Go::Rules::Group::group_remove(result_invert, Go::Stone::empty, 0, 0);
  ASSERT_EQ(expected, result_invert);

  Go::Rules::Group::group_remove(result_invert, Go::Stone::black, 0, 0);
  ASSERT_EQ(expected, result_invert);

  expected = Go::TwoDimensionArrayBoard<3, 3>{};
  expected.set(1, 1, Go::Stone::white);
  Go::Rules::Group::group_remove(result, Go::Stone::black, 0, 0);
  Go::Rules::Group::group_remove(result_invert, Go::Stone::white, 2, 2);
  EXPECT_EQ(expected, result);

  expected.set(1, 1, Go::Stone::black);
  EXPECT_EQ(expected, result_invert);
}

} // namespace
