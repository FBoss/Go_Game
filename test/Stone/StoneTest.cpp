#include "gtest/gtest.h"

#include "Stone.h"


// NOLINTNEXTLINE
TEST(Stone, Empty){
	EXPECT_EQ(0, static_cast<int>(Go::Stone::empty));
	EXPECT_NE(1, static_cast<int>(Go::Stone::empty));
	EXPECT_NE(2, static_cast<int>(Go::Stone::empty));
};


// NOLINTNEXTLINE
TEST(Stone, Black){
	EXPECT_NE(0, static_cast<int>(Go::Stone::black));
	EXPECT_EQ(1, static_cast<int>(Go::Stone::black));
	EXPECT_NE(2, static_cast<int>(Go::Stone::black));
};



// NOLINTNEXTLINE
TEST(Stone, White){
	EXPECT_NE(0, static_cast<int>(Go::Stone::white));
	EXPECT_NE(1, static_cast<int>(Go::Stone::white));
	EXPECT_EQ(2, static_cast<int>(Go::Stone::white));
};
