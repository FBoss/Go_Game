
#include <random>

namespace Go::GameEngine::Player {

template <typename Engine> struct RandomPlayer : public Player<ResignPlayer<Engine>, Engine>, Contestant<Engine> {
  RandomPlayer() : Contestant<Engine>{2000, "Random"} {};

  Move nextMove(Engine &engine, Stone stone) override { return generateRandomMove(engine, stone); }

private:
  std::default_random_engine generator;
};

} // namespace Go::GameEngine::Player
