#ifndef GO_BOARDTRANSFORMATION_H
#define GO_BOARDTRANSFORMATION_H

namespace Go::Util{

template<typename T>
constexpr auto rotate(const T & board) noexcept -> T {
    T value{};

    auto dim  = board.getDimension();

    for(auto i = 0; i < dim.row; ++i){
        for(auto j = 0; j < dim.column; ++j){
            auto x = dim.row-1-j;
            auto y = i;
            auto val = board.get(i,j);
            value.set(x, y, val);
        }
    }

return value;
}

} // namespace Go::Util

#endif // GO_BOARDTRANSFORMATION_H
