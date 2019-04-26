#ifndef LISTCOMMANDSCOMMAND_H
#define LISTCOMMANDSCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct ListCommandsCommand : public Command {
  constexpr explicit ListCommandsCommand(unsigned int id) noexcept : Command{id, "list_commands"} {};
  constexpr explicit ListCommandsCommand() noexcept : Command{std::nullopt, "list_commands"} {};
};

auto to_string(ListCommandsCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // LISTCOMMANDSCOMMAND_H
