#ifndef BITFIELDBOARD_H
#define BITFIELDBOARD_H

#include "Stone.h"
#include "Dimension.h"

#include <bitset>
#include <array>

namespace Go{

template<unsigned int Row, unsigned int Column>
class BitFieldBoard{
public:
    constexpr auto get(const unsigned int row, const unsigned int column) const {
        return static_cast<Stone>((mBoard.at(row).test(2*column+1) << 1) | mBoard.at(row).test(2*column));
    }
    constexpr void set(const unsigned int row, const unsigned int column, const Stone stone){
        std::bitset<2> binary {static_cast<unsigned int>(stone)};
        if(binary.test(0)){
            mBoard.at(row).set(2*column);
        }else{
            mBoard.at(row).reset(2*column);
        }

        if(binary.test(1)){
            mBoard.at(row).set(2*column+1);
        }else{
            mBoard.at(row).reset(2*column+1);
        }
    }

	constexpr auto getDimension(){
		return Dimension{Row,Column};
	};

	constexpr bool operator ==(const BitFieldBoard<Row, Column> &b) const {
        return mBoard == b.mBoard;
    };

    constexpr bool operator !=(const BitFieldBoard<Row, Column> &b) const {
            return mBoard != b.mBoard;
    };

private:    
    std::array<std::bitset<2*Column>, Row> mBoard;
};

} //namespace Go


#endif //BITFIELDBOARD_H
