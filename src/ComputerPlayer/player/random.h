#ifndef GO_COMPUTERPLAYER_RANDOM
#define GO_COMPUTERPLAYER_RANDOM

#include "player/player.h"

#include <random>

namespace Go::GameEngine::Player {

static std::default_random_engine generator{};

template <typename Engine> Move generateRandomMove(GameEngine<Engine> &engine, Stone stone) {
  // std::random_device r;
  //{r()};
  std::uniform_int_distribution<int> rowDistribution(0, engine.board().getDimension().row - 1);
  std::uniform_int_distribution<int> columnDistribution(0, engine.board().getDimension().column - 1);

  int row = rowDistribution(generator);
  int column = columnDistribution(generator);

  for (int limit = 1000; not engine.is_play_valid(stone, row, column); --limit) {
    row = rowDistribution(generator);
    column = columnDistribution(generator);

    if (limit <= 0) {
      return Move{MoveType::pass, {}};
    }
  }
  return Move{MoveType::move, {row, column}};
}

template <typename Engine> struct RandomPlayer : public Player<RandomPlayer<Engine>, Engine>, Contestant<Engine> {
  RandomPlayer() : Contestant<Engine>{2000, "Random"} {};

  Move nextMove(Engine &engine, Stone stone) override { return generateRandomMove(engine, stone); }

private:
  std::default_random_engine generator;
};

} // namespace Go::GameEngine::Player

#endif // GO_COMPUTERPLAYER_RANDOM
