#ifndef GO_RULES_GROUP_H
#define GO_RULES_GROUP_H

#include <Stone.h>

namespace Go::Rules::Group {

template <typename T> constexpr auto position_has_liberty(const T &board, const int row, const int column) noexcept {
  auto dim = board.getDimension();

  // bounds check
  if (not(row >= 0 && row < dim.row) || not(column >= 0 && column < dim.column)) {
    return false;
  }
  auto liberty = false;

  // check left
  if (row != 0) {
    liberty = board.get(row - 1, column) == Go::Stone::empty;
  }

  // check right
  if (row != dim.row - 1) {
    liberty = (board.get(row + 1, column) == Go::Stone::empty) | liberty;
  }

  // check up
  if (column != 0) {
    liberty = (board.get(row, column - 1) == Go::Stone::empty) | liberty;
  }

  // check down
  if (column != dim.column - 1) {
    liberty = (board.get(row, column + 1) == Go::Stone::empty) | liberty;
  }

  return liberty;
}

template <typename T> class group_has_liberty {
public:
  constexpr group_has_liberty(const T &board, const unsigned int row, const unsigned int column) noexcept
      : mBoard{board}, mColor{board.get(row, column)}, mRow{row}, mColumn{column} {}

  constexpr auto operator()() noexcept {
    return check_group_has_liberty(mRow, mColumn);
  }

private:
  const T &mBoard;
  T mVisited{};
  const Go::Stone mColor;
  const unsigned int mRow;
  const unsigned int mColumn;

  constexpr auto check_group_has_liberty(const int row, const int column) noexcept {
    // Recursion Base
    if (not(row >= 0 && row < mBoard.getDimension().row) || not(column >= 0 && column < mBoard.getDimension().column)) {
      return false;
    }

    auto stone = mBoard.get(row, column);
    if (stone == Go::Stone::empty) {
      return true;
    } else if (stone != mColor) {
      return false;
    }

    auto liberty = position_has_liberty(mBoard, row, column);
    if (liberty) {
      return true;
    }

    if (mVisited.get(row, column) != Go::Stone::empty) {
      return false;
    }
    mVisited.set(row, column, Go::Stone::black);

    // Recursion call
    if (check_group_has_liberty(row, column - 1)) {
      return true;
    }
    if (check_group_has_liberty(row - 1, column)) {
      return true;
    }
    if (check_group_has_liberty(row, column + 1)) {
      return true;
    }

    return check_group_has_liberty(row + 1, column);
  }
};

template <typename T>
constexpr auto group_remove(T &board, const Go::Stone color, const unsigned int row, const unsigned int column) noexcept {
  if (not(row >= 0 && row < board.getDimension().row) || not(column >= 0 && column < board.getDimension().column)) {
    return;
  }

  if (board.get(row, column) == color) {
    board.set(row, column, Go::Stone::empty);
  } else {
    return;
  }

  group_remove(board, color, row - 1, column);
  group_remove(board, color, row, column + 1);
  group_remove(board, color, row + 1, column);
  group_remove(board, color, row, column - 1);
}

} // namespace Go::Rules::Group

#endif // GO_RULES_GROUP_H
