#ifndef GTPCOMMANDPARAMETERPARSER_H
#define GTPCOMMANDPARAMETERPARSER_H

#include "Command.h"
// class Command;

namespace Go::GoTextProtocol::Util {

template <typename T> constexpr auto parse_parameter(const Go::GoTextProtocol::Command &command, std::string_view view = "") noexcept {
  return T{command.id};
}

} // namespace Go::GoTextProtocol::Util

#endif // GTPCOMMANDPARAMETERPARSER_H
