#ifndef FINALSCORECOMMAND_H
#define FINALSCORECOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct FinalScoreCommand : public Command {
  constexpr explicit FinalScoreCommand(unsigned int id) noexcept : Command{id, "final_score"} {};
  constexpr explicit FinalScoreCommand() noexcept : Command{std::nullopt, "final_score"} {};
};

auto to_string(FinalScoreCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // FINALSCORECOMMAND_H
