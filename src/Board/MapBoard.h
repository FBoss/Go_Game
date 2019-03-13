#ifndef MAPBOARD_H
#define MAPBOARD_H

#include "Dimension.h"
#include "Stone.h"

#include <map>
#include <stdexcept>

namespace Go {

template <unsigned int Row, unsigned int Column> class MapBoard {
public:
  constexpr auto get(const unsigned int row, const unsigned int column) const {
    if (row >= Row) {
      throw std::out_of_range("row out range");
    }
    if (column >= Column) {
      throw std::out_of_range("column out range");
    }

    const auto column_map = mBoard.find(row);
    if (column_map == mBoard.end()) {
      return Stone::empty;
    } else {
      const Stone stone = column_map->second.find(column)->second;
      return stone;
    }
  }
  constexpr void set(const unsigned int row, const unsigned int column, const Stone stone) {
    if (row >= Row) {
      throw std::out_of_range("row out range");
    }
    if (column >= Column) {
      throw std::out_of_range("column out range");
    }
    mBoard[row][column] = stone;
  }
  constexpr auto getDimension() { return Dimension{Row, Column}; };

  constexpr bool operator==(const MapBoard<Row, Column> &b) const { return mBoard == b.mBoard; };

  constexpr bool operator!=(const MapBoard<Row, Column> &b) const { return mBoard != b.mBoard; };

private:
  std::map<unsigned int, std::map<unsigned int, Stone>> mBoard;
};

} // namespace Go

#endif // MAPBOARD_H
