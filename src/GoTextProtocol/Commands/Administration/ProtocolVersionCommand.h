#ifndef PROTOCOLVERSIONCOMMAND_H
#define PROTOCOLVERSIONCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct ProtocolVersionCommand : public Command {
  constexpr explicit ProtocolVersionCommand(unsigned int id) noexcept : Command{id, "protocol_version"} {};
  constexpr explicit ProtocolVersionCommand() noexcept : Command{std::nullopt, "protocol_version"} {};
};

auto to_string(ProtocolVersionCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // PROTOCOLVERSIONCOMMAND_H
