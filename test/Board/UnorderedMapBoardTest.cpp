#include "gtest/gtest.h"

#include "BoardTestStructure.h"

#include "UnorderedMapBoard.h"

namespace {
using testing::Types;

typedef Types<Go::UnorderedMapBoard<0, 0>, Go::UnorderedMapBoard<4, 4>, Go::UnorderedMapBoard<9, 9>, Go::UnorderedMapBoard<13, 13>,
              Go::UnorderedMapBoard<17, 17>, Go::UnorderedMapBoard<19, 19>, Go::UnorderedMapBoard<100, 100>>
    BoardImplementations; // NOLINT

// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_CASE_P(UnorderedMapBoardTest, // Instance name
                              BoardTest,             // Test case name
                              BoardImplementations); // Type list

} // namespace
