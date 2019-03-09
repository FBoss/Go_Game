#ifndef TWODIMENSIONARRAYBOARD_H
#define TWODIMENSIONARRAYBOARD_H

#include "Stone.h"
#include "Dimension.h"

#include <array>

namespace Go{

template<unsigned int Row, unsigned int Column>
class TwoDimensionArrayBoard{
public:
    constexpr auto get(const unsigned int row, const unsigned int column) const {        
        return mBoard.at(row).at(column);
    }
    constexpr void set(const unsigned int row, const unsigned int column, const Stone stone){
        mBoard.at(row).at(column) = stone;
    }
    constexpr auto getDimension(){
	return Dimension{Row,Column};
    };

    constexpr bool operator ==(const TwoDimensionArrayBoard<Row, Column> &b) const {
        return mBoard == b.mBoard;
    };

    constexpr bool operator !=(const TwoDimensionArrayBoard<Row, Column> &b) const {
            return mBoard != b.mBoard;
    };

private:    
    std::array<std::array<Stone, Column>, Row> mBoard;
};

} //namespace Go


#endif //TWODIMENSIONARRAYBOARD_H
