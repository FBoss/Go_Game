#ifndef GTPCOMMANDEXTRACTOR_H
#define GTPCOMMANDEXTRACTOR_H

#include "Command.h"
#include "Integer.h"
#include "WordExtractor.h"
#include <string_view>

namespace Go::GoTextProtocol::Util {

constexpr auto extractCommand(std::string_view view) noexcept {

  WordExtractor extractor{view};

  auto first_word = extractor.nextWord();
  auto second_word = extractor.nextWord();

  auto command_text = first_word;

  std::optional<int> id = std::nullopt;
  if (Util::isInteger(std::string_view{first_word.data()})) {
    id = Util::toInt(std::string_view{first_word.data()});
    command_text = second_word;
  }
  Command command{id, command_text};
  return command;
}

} // namespace Go::GoTextProtocol::Util

#endif // GTPCOMMANDEXTRACTOR_H
