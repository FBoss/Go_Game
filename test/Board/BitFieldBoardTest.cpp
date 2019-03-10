#include "gtest/gtest.h"

#include "BoardTestStructure.h"

#include "BitFieldBoard.h"

namespace {
using testing::Types;

typedef Types<
	Go::BitFieldBoard<0,0>, 
	Go::BitFieldBoard<4,4>, 
	Go::BitFieldBoard<9,9>, 
	Go::BitFieldBoard<13,13>, 
	Go::BitFieldBoard<17,17>, 
	Go::BitFieldBoard<19,19>, 
	Go::BitFieldBoard<100,100>
> BoardImplementations; // NOLINT


// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_CASE_P(BitFieldBoardTest,    			// Instance name
                              BoardTest,      	// Test case name
                              BoardImplementations);  	// Type list

} // namespace
