#ifndef UNORDEREDMAPBOARD_H
#define UNORDEREDMAPBOARD_H

#include "Board.h"

#include "Dimension.h"
#include "Stone.h"

#include <stdexcept>
#include <unordered_map>

namespace Go {

template <unsigned int Row, unsigned int Column> class UnorderedMapBoard : public Board<UnorderedMapBoard<Row, Column>> {
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

  constexpr bool operator==(const UnorderedMapBoard<Row, Column> &b) const { return mBoard == b.mBoard; };

  constexpr bool operator!=(const UnorderedMapBoard<Row, Column> &b) const { return mBoard != b.mBoard; };

private:
  std::unordered_map<unsigned int, std::map<unsigned int, Stone>> mBoard;
};

} // namespace Go

#endif // UNORDEREDMAPBOARD_H
