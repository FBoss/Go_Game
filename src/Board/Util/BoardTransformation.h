#ifndef GO_BOARDTRANSFORMATION_H
#define GO_BOARDTRANSFORMATION_H

#include "Board.h"
#include "Stone.h"

namespace Go::Util{

template<typename T>
constexpr auto rotate(const T & board) noexcept -> T {
    T value{};

    auto dim = board.getDimension();

    for (auto i = 0; i < dim.row; ++i) {
        for (auto j = 0; j < dim.column; ++j) {
            auto x = dim.row - 1 - j;
            auto y = i;
            auto val = board.get(i, j);
            value.set(x, y, val);
        }
    }

    return value;
}

template <typename T>
constexpr auto invert(const T & board) noexcept -> T {
    T value{};

    auto dim = board.getDimension();

    for (auto i = 0; i < dim.row; ++i) {
        for (auto j = 0; j < dim.column; ++j) {
            auto val = board.get(i,j);
            if(val == Go::Stone::black){
                value.set(i,j, Go::Stone::white);
            }else if(val == Go::Stone::white){
                value.set(i,j, Go::Stone::black);
            }
        }
    }

    return value;
}

} // namespace Go::Util

#endif // GO_BOARDTRANSFORMATION_H
