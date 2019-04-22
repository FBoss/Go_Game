#ifndef GTPWORDEXTRACTOR_H
#define GTPWORDEXTRACTOR_H

#include <string_view>

namespace Go::GoTextProtocol::Util {

constexpr auto maxWordLength() { return 20; }

using Word = std::array<char, maxWordLength() + 1>;

constexpr auto skip_character(char character) noexcept { return character <= ' ' || (character == 127); }

class WordExtractor {
public:
  constexpr WordExtractor(const std::string_view view) noexcept : input{view} {}
  constexpr WordExtractor() noexcept = default;

  constexpr auto nextWord() noexcept {
    Word word{};

    size_t word_index = 0;

    for (auto iterator = input.begin(); iterator != input.end() && word_index < word.size(); ++iterator) {
      auto character = *iterator;
      if (character == ' ' || character == '\t' || character == '\n') {
        break;
      }
      if (skip_character(character)) {
        continue;
      }

      word.at(word_index) = character;
      ++word_index;
    }

    auto word_separator_index = input.find_first_of("\t\n ");

    if (word_separator_index == std::string_view::npos) {
      input = input.substr(0, 0);
    } else {
      auto last_index = input.size() - word_separator_index;
      input = input.substr(word_separator_index + 1, last_index);
    }

    word.at(maxWordLength()) = '\0';
    return word;
  }

private:
  std::string_view input{};
};
} // namespace Go::GoTextProtocol::Util

#endif // GTPWORDEXTRACTOR_H
