#include "gtest/gtest.h"

#include "BoardTestStructure.h"

#include "TwoDimensionArrayBoard.h"

namespace {
using testing::Types;

typedef Types<
	Go::TwoDimensionArrayBoard<0,0>, 
	Go::TwoDimensionArrayBoard<4,4>, 
	Go::TwoDimensionArrayBoard<9,9>, 
	Go::TwoDimensionArrayBoard<13,13>, 
	Go::TwoDimensionArrayBoard<17,17>, 
	Go::TwoDimensionArrayBoard<19,19>, 
	Go::TwoDimensionArrayBoard<100,100>
> BoardImplementations; // NOLINT


// NOLINTNEXTLINE
INSTANTIATE_TYPED_TEST_CASE_P(TwoDimensionArrayBoardTest,    			// Instance name
                              BoardTest,      	// Test case name
                              BoardImplementations);  	// Type list

} // namespace
