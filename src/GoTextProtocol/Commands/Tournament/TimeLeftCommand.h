#ifndef TIMELEFTCOMMAND_H
#define TIMELEFTCOMMAND_H

#include "Command.h"
#include "Stone.h"
#include <optional>

namespace Go::GoTextProtocol {

struct TimeLeftCommand : public Command {
  Stone color;
  unsigned int time = 0;
  unsigned int stones = 0;
  constexpr explicit TimeLeftCommand(const unsigned int id, const Stone color, const unsigned int time, const unsigned int stones) noexcept
      : Command({id, "time_left"}), color{color}, time{time}, stones{stones} {};
  constexpr explicit TimeLeftCommand(const Stone color, const unsigned int time, const unsigned int stones) noexcept
      : Command({std::nullopt, "time_left"}), color{color}, time{time}, stones{stones} {};
};

auto to_string(TimeLeftCommand const &command) {
  return to_string(static_cast<Command>(command)) + " " + to_string(command.color) + " " + std::to_string(command.time) + " " +
         std::to_string(command.stones) + '\n';
}
} // namespace Go::GoTextProtocol

#endif // TIMELEFTCOMMAND_H
