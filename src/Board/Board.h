#ifndef BOARD_H
#define BOARD_H

#include "Dimension.h"
#include "Stone.h"

namespace Go {

struct Point {
  int row;
  int column;
};

constexpr bool operator==(const Point &lhs, const Point &rhs) { return lhs.row == rhs.row && lhs.column == rhs.column; }
constexpr bool operator!=(const Point &lhs, const Point &rhs) { return lhs.row != rhs.row || lhs.column != rhs.column; }

template <typename BOARD> struct Board {
  auto get(const Point &point) const { return static_cast<BOARD const *>(this)->get(point.row, point.column); }
  void set(const Point &point, Stone stone) { static_cast<BOARD *>(this)->set(point.row, point.column, stone); }

  Dimension getDimension() { return static_cast<BOARD *>(this)->getDimension(); };

  bool operator==(const BOARD &board) const { return static_cast<BOARD &>(this) == board; };
  bool operator!=(const BOARD &board) const { return static_cast<BOARD &>(this) != board; };
};

template <typename T> constexpr bool isPointValid(const Point &point) {
  if (point.row < 0 || point.column < 0) {
    return false;
  }

  if (const auto dimension = Board<T>{}.getDimension(); not(point.row < dimension.row) || not(point.column < dimension.column)) {
    return false;
  }

  return true;
}

} // namespace Go

#endif // BOARD_H
