#ifndef GTPCOMMAND_H
#define GTPCOMMAND_H

#include "Word.h"
#include <optional>
#include <sstream>
#include <string_view>

namespace Go::GoTextProtocol {

struct Command {
  std::optional<unsigned int> id = std::nullopt;
  const Word command;
};

inline auto to_string(Command const &command) {
  if (command.id.has_value()) {
    return std::to_string(command.id.value()) + ' ' + std::string{command.command.data()};
  } else {

    return std::string{command.command.data()};
  }
}

inline auto to_string(const float value) {
  std::stringstream ss;
  ss << value;
  return ss.str();
}
} // namespace Go::GoTextProtocol

#endif // GTPCOMMAND_H
