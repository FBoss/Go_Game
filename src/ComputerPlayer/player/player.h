#ifndef GO_COMPUTERPLAYER_PLAYER
#define GO_COMPUTERPLAYER_PLAYER

#include "Board.h"
#include "Stone.h"

#include <string>

namespace Go::GameEngine::Player {

enum class MoveType { move, pass, resign };

struct Move {
  MoveType type;
  Point point;
};

template <typename PLAYER, typename Engine> struct Player {
  Move nextMove(Engine &engine, Stone stone) { return static_cast<PLAYER *>(this)->nextMove(engine, stone); }
};

template <typename Engine> struct Contestant {
  Contestant(int rank, std::string contestant_name) : ranking{rank}, name{contestant_name} {}
  virtual Move nextMove(Engine &engine, Stone stone) = 0;

  int ranking;
  std::string name;
};

} // namespace Go::GameEngine::Player

#endif // GO_COMPUTERPLAYER_PLAYER
