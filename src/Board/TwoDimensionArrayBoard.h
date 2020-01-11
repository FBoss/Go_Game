#ifndef TWODIMENSIONARRAYBOARD_H
#define TWODIMENSIONARRAYBOARD_H

#include "Board.h"

#include "Dimension.h"
#include "Stone.h"

#include <array>

namespace Go {

template <int Row, int Column> class TwoDimensionArrayBoard : public Board<TwoDimensionArrayBoard<Row, Column>> {
public:
  constexpr auto get(const int row, const int column) const { return mBoard.at(row).at(column); }
  constexpr void set(const int row, const int column, const Stone stone) { mBoard.at(row).at(column) = stone; }
  constexpr auto getDimension() const noexcept { return Dimension{Row, Column}; };

  constexpr bool operator==(const TwoDimensionArrayBoard<Row, Column> &b) const { return mBoard == b.mBoard; };

  constexpr bool operator!=(const TwoDimensionArrayBoard<Row, Column> &b) const { return mBoard != b.mBoard; };

private:
  std::array<std::array<Stone, Column>, Row> mBoard;
};

} // namespace Go

#endif // TWODIMENSIONARRAYBOARD_H
