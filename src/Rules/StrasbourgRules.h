#ifndef STRASBOURGRULSE_H
#define STRASBOURGRULSE_H

#include <stdexcept>

namespace Go::Rulset {

enum class GameState { black_turn, white_turn, game_over };

using IllegalMove = std::runtime_error;

template <typename BOARD> class StrasbourgRules {
public:
  constexpr auto black_move(unsigned int row, unsigned int column) {
    if (mState != GameState::black_turn) {
      throw IllegalMove("Not blacks turn");
    } else if (mBoard.get(row, column) != Go::Stone::empty) {
      throw IllegalMove("Not empty point");
    }
    mBoard.set(row, column, Go::Stone::black);
    mState = GameState ::white_turn;
  };

  constexpr auto white_move(unsigned int row, unsigned int column) {
    if (mState != GameState::white_turn) {
      throw IllegalMove("Not whites turn");
    } else if (mBoard.get(row, column) != Go::Stone::empty) {
      throw IllegalMove("Not empty point");
    }
    mBoard.set(row, column, Go::Stone::white);
    mState = GameState ::black_turn;
  };

  constexpr auto getBoard() noexcept { return mBoard; };

  constexpr auto game_state() noexcept { return mState; };

private:
  BOARD mBoard{};
  GameState mState = GameState::black_turn;
};
} // namespace Go::Rulset

#endif // STRASBOURGRULSE_H
