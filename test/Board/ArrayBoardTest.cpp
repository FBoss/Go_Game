#include "gtest/gtest.h"

#include "BoardTestStructure.h"

#include "ArrayBoard.h"

namespace {
using testing::Types;

typedef Types<Go::ArrayBoard<0, 0>, Go::ArrayBoard<4, 4>, Go::ArrayBoard<9, 9>, Go::ArrayBoard<13, 13>, Go::ArrayBoard<17, 17>,
              Go::ArrayBoard<19, 19>, Go::ArrayBoard<100, 100>>
    BoardImplementations; // NOLINT

// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_CASE_P(ArrayBoardTest,        // Instance name
                              BoardTest,             // Test case name
                              BoardImplementations); // Type list

} // namespace
