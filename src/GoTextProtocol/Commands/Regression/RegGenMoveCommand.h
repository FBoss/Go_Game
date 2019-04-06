#ifndef REGGENMOVECOMMAND_H
#define REGGENMOVECOMMAND_H

#include "Command.h"
#include "Stone.h"
#include <optional>

namespace Go::GoTextProtocol {

struct RegGenMoveCommand : public Command {
  Stone color;
  constexpr explicit RegGenMoveCommand(const unsigned int id, const Stone color) noexcept : Command({id, "reg_genmove"}), color{color} {};
  constexpr explicit RegGenMoveCommand(const Stone color) noexcept : Command({std::nullopt, "reg_genmove"}), color{color} {};
};

auto to_string(RegGenMoveCommand const &command) {
  return to_string(static_cast<Command>(command)) + " " + to_string(command.color) + '\n';
}
} // namespace Go::GoTextProtocol

#endif // REGGENMOVECOMMAND_H
