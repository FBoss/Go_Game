#ifndef GTPINTEGER_H
#define GTPINTEGER_H

#include <string_view>

namespace Go::GoTextProtocol::Util {

constexpr auto isDigit(char character) noexcept { return character >= '0' && character <= '9'; }

constexpr auto isInteger(std::string_view view) noexcept {
  if (view.empty()) {
    return false;
  }
  for (auto character : view) {
    if (not isDigit(character))
      return false;
  }
  return true;
}

constexpr auto toInt(std::string_view view) noexcept {
  auto value = 0;

  for (auto character : view) {
    value = value * 10;
    value += character - '0';
  }

  return value;
}

} // namespace Go::GoTextProtocol::Util

#endif // GTPINTEGER_H
