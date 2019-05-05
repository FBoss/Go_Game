#include "Util/BoardTransformation.h"
#include "TwoDimensionArrayBoard.h"

#include "gtest/gtest.h"

namespace {

    class BoardTransformationTest : public ::testing::Test {

    protected:
        void SetUp() override {  }
        void TearDown() override {}

    public:
        const Go::TwoDimensionArrayBoard<3,3> mBoard3x3 = [](){
            Go::TwoDimensionArrayBoard<3,3> board{};

            board.set(0,0, Go::Stone::empty);
            board.set(0,1, Go::Stone::white);
            board.set(0,2, Go::Stone::black);
            board.set(1,0, Go::Stone::white);
            board.set(1,1, Go::Stone::black);
            board.set(1,2, Go::Stone::empty);
            board.set(2,0, Go::Stone::white);
            board.set(2,1, Go::Stone::black);
            board.set(2,2, Go::Stone::empty);

            return board;
        }();

        const Go::TwoDimensionArrayBoard<3,3> mBoard3x3_90Degree = [](){
            Go::TwoDimensionArrayBoard<3,3> board{};

            board.set(0,0, Go::Stone::black);
            board.set(0,1, Go::Stone::empty);
            board.set(0,2, Go::Stone::empty);
            board.set(1,0, Go::Stone::white);
            board.set(1,1, Go::Stone::black);
            board.set(1,2, Go::Stone::black);
            board.set(2,0, Go::Stone::empty);
            board.set(2,1, Go::Stone::white);
            board.set(2,2, Go::Stone::white);

            return board;
        }();

        const Go::TwoDimensionArrayBoard<3,3> mBoard3x3_180Degree = [](){
            Go::TwoDimensionArrayBoard<3,3> board{};

            board.set(0,0, Go::Stone::empty);
            board.set(0,1, Go::Stone::black);
            board.set(0,2, Go::Stone::white);
            board.set(1,0, Go::Stone::empty);
            board.set(1,1, Go::Stone::black);
            board.set(1,2, Go::Stone::white);
            board.set(2,0, Go::Stone::black);
            board.set(2,1, Go::Stone::white);
            board.set(2,2, Go::Stone::empty);

            return board;
        }();

        const Go::TwoDimensionArrayBoard<3,3> mBoard3x3_270Degree = [](){
            Go::TwoDimensionArrayBoard<3,3> board{};

            board.set(0,0, Go::Stone::white);
            board.set(0,1, Go::Stone::white);
            board.set(0,2, Go::Stone::empty);
            board.set(1,0, Go::Stone::black);
            board.set(1,1, Go::Stone::black);
            board.set(1,2, Go::Stone::white);
            board.set(2,0, Go::Stone::empty);
            board.set(2,1, Go::Stone::empty);
            board.set(2,2, Go::Stone::black);

            return board;
        }();

        const Go::TwoDimensionArrayBoard<4,4> mBoard4x4 = [](){
            Go::TwoDimensionArrayBoard<4,4> board{};

            board.set(0,0, Go::Stone::empty);
            board.set(0,1, Go::Stone::white);
            board.set(0,2, Go::Stone::empty);
            board.set(0,3, Go::Stone::white);
            board.set(1,0, Go::Stone::empty);
            board.set(1,1, Go::Stone::empty);
            board.set(1,2, Go::Stone::black);
            board.set(1,3, Go::Stone::empty);
            board.set(2,0, Go::Stone::empty);
            board.set(2,1, Go::Stone::white);
            board.set(2,2, Go::Stone::empty);
            board.set(2,3, Go::Stone::black);
            board.set(3,0, Go::Stone::black);
            board.set(3,1, Go::Stone::empty);
            board.set(3,2, Go::Stone::empty);
            board.set(3,3, Go::Stone::empty);

            return board;
        }();

        const Go::TwoDimensionArrayBoard<4,4> mBoard4x4_90Degree = [](){
            Go::TwoDimensionArrayBoard<4,4> board{};

            board.set(0,0, Go::Stone::white);
            board.set(0,1, Go::Stone::empty);
            board.set(0,2, Go::Stone::black);
            board.set(0,3, Go::Stone::empty);
            board.set(1,0, Go::Stone::empty);
            board.set(1,1, Go::Stone::black);
            board.set(1,2, Go::Stone::empty);
            board.set(1,3, Go::Stone::empty);
            board.set(2,0, Go::Stone::white);
            board.set(2,1, Go::Stone::empty);
            board.set(2,2, Go::Stone::white);
            board.set(2,3, Go::Stone::empty);
            board.set(3,0, Go::Stone::empty);
            board.set(3,1, Go::Stone::empty);
            board.set(3,2, Go::Stone::empty);
            board.set(3,3, Go::Stone::black);

            return board;
        }();


        const Go::TwoDimensionArrayBoard<4,4> mBoard4x4_180Degree = [](){
            Go::TwoDimensionArrayBoard<4,4> board{};

            board.set(0,0, Go::Stone::empty);
            board.set(0,1, Go::Stone::empty);
            board.set(0,2, Go::Stone::empty);
            board.set(0,3, Go::Stone::black);
            board.set(1,0, Go::Stone::black);
            board.set(1,1, Go::Stone::empty);
            board.set(1,2, Go::Stone::white);
            board.set(1,3, Go::Stone::empty);
            board.set(2,0, Go::Stone::empty);
            board.set(2,1, Go::Stone::black);
            board.set(2,2, Go::Stone::empty);
            board.set(2,3, Go::Stone::empty);
            board.set(3,0, Go::Stone::white);
            board.set(3,1, Go::Stone::empty);
            board.set(3,2, Go::Stone::white);
            board.set(3,3, Go::Stone::empty);

            return board;
        }();

        const Go::TwoDimensionArrayBoard<4,4> mBoard4x4_270Degree = [](){
            Go::TwoDimensionArrayBoard<4,4> board{};

            board.set(0,0, Go::Stone::black);
            board.set(0,1, Go::Stone::empty);
            board.set(0,2, Go::Stone::empty);
            board.set(0,3, Go::Stone::empty);
            board.set(1,0, Go::Stone::empty);
            board.set(1,1, Go::Stone::white);
            board.set(1,2, Go::Stone::empty);
            board.set(1,3, Go::Stone::white);
            board.set(2,0, Go::Stone::empty);
            board.set(2,1, Go::Stone::empty);
            board.set(2,2, Go::Stone::black);
            board.set(2,3, Go::Stone::empty);
            board.set(3,0, Go::Stone::empty);
            board.set(3,1, Go::Stone::black);
            board.set(3,2, Go::Stone::empty);
            board.set(3,3, Go::Stone::white);

            return board;
        }();
    };


    TEST_F(BoardTransformationTest, emptyBoard) {
        Go::TwoDimensionArrayBoard<3,3> begin{};
        auto rot = Go::Util::rotate(begin);
        EXPECT_EQ(begin, rot);
    }



    TEST_F(BoardTransformationTest, 3x3_90) {
        auto rot = Go::Util::rotate(mBoard3x3);
        EXPECT_EQ(mBoard3x3_90Degree, rot);
    }

    TEST_F(BoardTransformationTest, 3x3_180) {
        auto rot = Go::Util::rotate(mBoard3x3);
        rot = Go::Util::rotate(rot);
        EXPECT_EQ(mBoard3x3_180Degree, rot);
    }

    TEST_F(BoardTransformationTest, 3x3_270) {
        auto rot = Go::Util::rotate(mBoard3x3);
        rot = Go::Util::rotate(rot);
        rot = Go::Util::rotate(rot);
        EXPECT_EQ(mBoard3x3_270Degree, rot);
    }

    TEST_F(BoardTransformationTest, 3x3_360) {
        auto rot = Go::Util::rotate(mBoard3x3);
        rot = Go::Util::rotate(rot);
        rot = Go::Util::rotate(rot);
        rot = Go::Util::rotate(rot);
        EXPECT_EQ(mBoard3x3, rot);
    }


    TEST_F(BoardTransformationTest, 4x4_90) {
        auto rot = Go::Util::rotate(mBoard4x4);
        EXPECT_EQ(mBoard4x4_90Degree, rot);
    }

    TEST_F(BoardTransformationTest, 4x4_180) {
        auto rot = Go::Util::rotate(mBoard4x4);
        rot = Go::Util::rotate(rot);
        EXPECT_EQ(mBoard4x4_180Degree, rot);
    }

    TEST_F(BoardTransformationTest, 4x4_270) {
        auto rot = Go::Util::rotate(mBoard4x4);
        rot = Go::Util::rotate(rot);
        rot = Go::Util::rotate(rot);
        EXPECT_EQ(mBoard4x4_270Degree, rot);
    }

    TEST_F(BoardTransformationTest, 4x4_360) {
        auto rot = Go::Util::rotate(mBoard4x4);
        rot = Go::Util::rotate(rot);
        rot = Go::Util::rotate(rot);
        rot = Go::Util::rotate(rot);
        EXPECT_EQ(mBoard4x4, rot);
    }

} // namespace