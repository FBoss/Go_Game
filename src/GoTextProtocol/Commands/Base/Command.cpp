#include "Command.h"

auto Go::GoTextProtocol::to_string(Command const &command) -> std::string {
  if (command.id.has_value()) {
    return std::to_string(command.id.value()) + ' ' + std::string{command.command.data()};
  } else {

    return std::string{command.command.data()};
  }
}

auto Go::GoTextProtocol::to_string(const float value) -> std::string {
  std::stringstream ss;
  ss << value;
  return ss.str();
}