#ifndef GO_TERRITORY_SCORING
#define GO_TERRITORY_SCORING

#include "Stone.h"
#include <functional>

namespace Go::Rules {

struct Score {
  int white = 0;
  int black = 0;
  int empty = 0;
};

template <typename T> constexpr auto floodfill(const T &board, int x, int y, Go::Stone color, T &destination) noexcept {
  const auto dim = board.getDimension();
  if (x < 0 || x >= dim.row) {
    return;
  } else if (y < 0 || y >= dim.column) {
    return;
  } else if (destination.get(x, y) != Go::Stone::empty) {
    return;
  } else if (board.get(x, y) == Go::Stone::empty) {
    destination.set(x, y, color);
  } else {
    return;
  }

  floodfill(board, x - 1, y, color, destination);
  floodfill(board, x, y - 1, color, destination);
  floodfill(board, x + 1, y, color, destination);
  floodfill(board, x, y + 1, color, destination);
}

template <typename T> constexpr auto score_territory(const T &board) noexcept {
  T black{};
  T white{};

  const auto dim = board.getDimension();

  for (int i = 0; i < dim.row; ++i) {
    for (int j = 0; j < dim.column; ++j) {
      auto color = board.get(i, j);
      if (color == Go::Stone::black) {
        floodfill(board, i - 1, j, color, black);
        floodfill(board, i, j - 1, color, black);
        floodfill(board, i + 1, j, color, black);
        floodfill(board, i, j + 1, color, black);
      } else if (color == Go::Stone::white) {
        floodfill(board, i - 1, j, color, white);
        floodfill(board, i, j - 1, color, white);
        floodfill(board, i + 1, j, color, white);
        floodfill(board, i, j + 1, color, white);
      }
    }
  }

  Score score{};

  for (int i = 0; i < dim.row; ++i) {
    for (int j = 0; j < dim.column; ++j) {
      auto state_white = white.get(i, j);
      auto state_black = black.get(i, j);

      if (state_white == state_black) {
        ++score.empty;
      } else if (state_white == Go::Stone::empty && state_black == Go::Stone::black) {
        ++score.black;
      } else if (state_black == Go::Stone::empty && state_white == Go::Stone::white) {
        ++score.white;
      } else {
        ++score.empty;
      }
    }
  }

  return score;
}

} // namespace Go::Rules

#endif // GO_TERRITORY_SCORING
