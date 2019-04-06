#ifndef VERTEXCOMMANDTEST_H
#define VERTEXCOMMANDTEST_H

#include "Vertex.h"

namespace {
    TEST(Vertex, 0x0_A1) {
    auto test = Go::GoTextProtocol::to_string(Go::GoTextProtocol::Vertex{0, 0});

    EXPECT_EQ("A1", test);
}

TEST(Vertex, 7x8_H9) {

auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{7, 8});

EXPECT_EQ("H9", test);
}

TEST(Vertex, 8x7_J8) {

auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{8, 7});

EXPECT_EQ("J8", test);
}

TEST(Vertex, 24x24_Z25) {

auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{24, 24});

EXPECT_EQ("Z25", test);
}

    TEST(Vertex, 25x25_AA26) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{25, 25});

        EXPECT_EQ("AA26", test);
    }

    TEST(Vertex, 26x26_AB27) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{26, 26});

        EXPECT_EQ("AB27", test);
    }

    TEST(Vertex, 142x142_AB143) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{142, 142});

        EXPECT_EQ("ES143", test);
    }
    TEST(Vertex, 649x649_ZZ650) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{649, 649});

        EXPECT_EQ("ZZ650", test);
    }
    TEST(Vertex, 650x650_ZZ650) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{650, 650});

        EXPECT_EQ("AAA651", test);
    }

    TEST(Vertex, 933x933_ZZ934) {

        auto test = Go::GoTextProtocol::to_string( Go::GoTextProtocol::Vertex{933, 933});

        EXPECT_EQ("AMJ934", test);
    }


} //namespace


#endif //VERTEXCOMMANDTEST_H
