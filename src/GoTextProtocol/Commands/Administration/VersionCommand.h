#ifndef VERSIONCOMMAND_H
#define VERSIONCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

struct VersionCommand : public Command {
  constexpr explicit VersionCommand(unsigned int id) noexcept : Command({id, "version"}){};
  constexpr explicit VersionCommand() noexcept : Command({std::nullopt, "version"}){};
};

auto to_string(VersionCommand const &command) { return to_string(static_cast<Command>(command)) + '\n'; }
} // namespace Go::GoTextProtocol

#endif // VERSIONCOMMAND_H
