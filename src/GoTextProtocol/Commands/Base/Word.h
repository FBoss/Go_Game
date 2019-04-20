#ifndef GTPWORD_H
#define GTPWORD_H

#include <array>

namespace Go::GoTextProtocol {
using Word = std::array<char, 21>;

constexpr auto max_word_length() { return Word().size() - 1; }
} // namespace Go::GoTextProtocol

#endif // GTPWORD_H
