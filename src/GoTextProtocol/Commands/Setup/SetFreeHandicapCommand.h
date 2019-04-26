#ifndef SETFREEHANDICAPCOMMAND_H
#define SETFREEHANDICAPCOMMAND_H

#include "Command.h"
#include "Vertex.h"
#include <array>
#include <optional>

namespace Go::GoTextProtocol {

template <unsigned int T> struct SetFreeHandicapCommand : public Command {
  const std::array<Vertex, T> vertices;
  constexpr explicit SetFreeHandicapCommand(const unsigned int id, const std::array<Vertex, T> &&vertices) noexcept
      : Command{id, "set_free_handicap"}, vertices{vertices} {};
  constexpr explicit SetFreeHandicapCommand(const std::array<Vertex, T> &&vertices) noexcept
      : Command{std::nullopt, "set_free_handicap"}, vertices{vertices} {};
};

template <unsigned int T> auto to_string(SetFreeHandicapCommand<T> const &command) {
  std::string vertices;
  for (auto &vertex : command.vertices) {
    vertices.append(" " + to_string(vertex));
  }
  return to_string(static_cast<Command>(command)) + vertices + '\n';
}
} // namespace Go::GoTextProtocol

#endif // SETFREEHANDICAPCOMMAND_H
