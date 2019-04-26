#ifndef KNOWNCOMMANDCOMMAND_H
#define KNOWNCOMMANDCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct KnownCommandCommand : public Command {
  constexpr explicit KnownCommandCommand(const unsigned int id) noexcept : Command{id, "known_command"} {};
  constexpr explicit KnownCommandCommand() noexcept : Command{std::nullopt, "known_command"} {};
};

auto to_string(KnownCommandCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }

} // namespace Go::GoTextProtocol

#endif // KNOWNCOMMANDCOMMAND_H
