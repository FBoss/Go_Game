#include "gtest/gtest.h"

#include "BoardTestStructure.h"

#include "MapBoard.h"

namespace {
using testing::Types;

typedef Types<Go::MapBoard<0, 0>, Go::MapBoard<4, 4>, Go::MapBoard<9, 9>, Go::MapBoard<13, 13>, Go::MapBoard<17, 17>, Go::MapBoard<19, 19>,
              Go::MapBoard<100, 100>>
    BoardImplementations; // NOLINT

// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_CASE_P(MapBoardTest,          // Instance name
                              BoardTest,             // Test case name
                              BoardImplementations); // Type list

} // namespace
