#ifndef QUITCOMMAND_H
#define QUITCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct QuitCommand : public Command {
  constexpr explicit QuitCommand(unsigned int id) noexcept : Command({id, "quit"}){};
  constexpr explicit QuitCommand() noexcept : Command({std::nullopt, "quit"}){};
};

auto to_string(QuitCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }

} // namespace Go::GoTextProtocol

#endif // QUITCOMMAND_H
