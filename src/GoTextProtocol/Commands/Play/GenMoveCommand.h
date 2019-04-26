#ifndef GENMOVECOMMAND_H
#define GENMOVECOMMAND_H

#include "Command.h"
#include "Stone.h"
#include <optional>

namespace Go::GoTextProtocol {

struct GenMoveCommand : public Command {
  Stone color;
  constexpr explicit GenMoveCommand(const unsigned int id, const Stone stone) noexcept : Command{id, "genmove"}, color{stone} {};
  constexpr explicit GenMoveCommand(const Stone stone) noexcept : Command{std::nullopt, "genmove"}, color{stone} {};
};

auto to_string(GenMoveCommand const &command) { return to_string(static_cast<Command>(command)) + " " + to_string(command.color) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // GENMOVECOMMAND_H
