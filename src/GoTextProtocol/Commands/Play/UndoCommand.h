#ifndef UNDOCOMMAND_H
#define UNDOCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct UndoCommand : public Command {
  constexpr explicit UndoCommand(unsigned int id) noexcept : Command{id, "undo"} {};
  constexpr explicit UndoCommand() noexcept : Command{std::nullopt, "undo"} {};
};

auto to_string(UndoCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // UNDOCOMMAND_H
