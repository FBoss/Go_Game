#ifndef STRASBOURGRULSE_H
#define STRASBOURGRULSE_H

namespace Go::Rulset {

enum class GameState { black_turn, white_turn, game_over };

template <typename BOARD> class StrasbourgRules {
public:
  constexpr auto black_move(unsigned int row, unsigned int column) { mBoard.set(row, column, Go::Stone::black); };

  constexpr auto white_move(unsigned int row, unsigned int column) { mBoard.set(row, column, Go::Stone::white); };

  constexpr auto getBoard() noexcept { return mBoard; };

private:
  BOARD mBoard{};
};
} // namespace Go::Rulset

#endif // STRASBOURGRULSE_H
