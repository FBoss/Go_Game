#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Board.h"

namespace Go::GameEngine {

struct Prisoners {
  int black;
  int white;
};

constexpr bool operator==(const Prisoners &lhs, const Prisoners &rhs) { return lhs.black == rhs.black && lhs.white == rhs.white; }

constexpr bool operator!=(const Prisoners &lhs, const Prisoners &rhs) { return lhs.black != rhs.black || lhs.white != rhs.white; }

template <typename Engine> struct GameEngine {
  void play_black(int row, int column) { static_cast<Engine *>(this)->play_black(row, column); }

  void play_white(int row, int column) { static_cast<Engine *>(this)->play_white(row, column); }

  void play_black_pass() { static_cast<Engine *>(this)->play_black_pass(); }

  void play_white_pass() { static_cast<Engine *>(this)->play_white_pass(); }

  bool is_play_valid(Stone stone, int row, int column) { return static_cast<Engine *>(this)->is_play_valid(stone, row, column); }

  const auto &board() { return static_cast<Engine *>(this)->board(); }

  const Prisoners &prisoners() { return static_cast<Engine *>(this)->prisoners(); }
};

} // namespace Go::GameEngine

#endif // GAME_ENGINE_H
