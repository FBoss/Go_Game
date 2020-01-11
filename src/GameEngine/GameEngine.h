#ifndef GAME_ENGINE_H
#define GAME_ENGINE_H

#include "Board.h"

namespace Go::GameEngine {

template <typename Engine, typename BoardType> struct GameEngine {
  const Board<BoardType> &get board() {}
}

} // namespace Go::GameEngine

#endif // GAME_ENGINE_H
