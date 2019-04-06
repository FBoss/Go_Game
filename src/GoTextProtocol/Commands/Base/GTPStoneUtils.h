#ifndef GTPSTONEUTILS_H
#define GTPSTONEUTILS_H

#include "Stone.h"

namespace Go::GoTextProtocol {

constexpr auto to_string(Stone const &stone) noexcept {
  switch (stone) {
  case Stone::black:
    return "B";
  case Stone::white:
    return "W";
  case Stone ::empty:
    return "E";
  default:
    return "_";
  }
}

} // namespace Go::GoTextProtocol

#endif // GTPSTONEUTILS_H
