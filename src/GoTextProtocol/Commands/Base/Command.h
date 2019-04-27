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

std::string to_string(Command const &command);

std::string to_string(const float value);

} // namespace Go::GoTextProtocol

#endif // GTPCOMMAND_H
