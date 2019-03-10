#ifndef ARRAYBOARD_H
#define ARRAYBOARD_H

#include "Dimension.h"
#include "Stone.h"

#include <array>
#include <stdexcept>

namespace Go {

template <unsigned int Row, unsigned int Column> class ArrayBoard {
public:
  constexpr auto get(const unsigned int row, const unsigned int column) const { return mBoard.at(calculateIndex(row, column)); }
  constexpr void set(const unsigned int row, const unsigned int column, const Stone stone) { mBoard.at(calculateIndex(row, column)) = stone; }
  constexpr auto getDimension() { return Dimension{Row, Column}; };

  constexpr bool operator==(const ArrayBoard<Row, Column> &b) const { return mBoard == b.mBoard; };

  constexpr bool operator!=(const ArrayBoard<Row, Column> &b) const { return mBoard != b.mBoard; };

private:
  std::array<Stone, Row * Column> mBoard;

  constexpr static unsigned int calculateIndex(const unsigned int row, const unsigned int column){
		if(row >= Row)
			throw std::out_of_range("row index out of bounds");
		if(column >= Column)
			throw std::out_of_range("column index out of bounds");
	
		return column + row*column;
	};
};

} // namespace Go

#endif // ARRAYBOARD_H
