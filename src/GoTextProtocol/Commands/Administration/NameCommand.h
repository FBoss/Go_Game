#ifndef NAMECOMMAND_H
#define NAMECOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct NameCommand : public Command {
  constexpr explicit NameCommand(unsigned int id) noexcept : Command({id, "name"}){};
  constexpr explicit NameCommand() noexcept : Command({std::nullopt, "name"}){};
};

auto to_string(NameCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // NAMECOMMAND_H
