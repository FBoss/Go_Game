#ifndef PLAYCOMMAND_H
#define PLAYCOMMAND_H

#include "Command.h"
#include "Move.h"
#include <optional>
#include <variant>

namespace Go::GoTextProtocol {

struct PlayCommand : public Command {
  std::variant<VertexMove, PassMove, ResignMove> move;
  constexpr explicit PlayCommand(const unsigned int id, std::variant<VertexMove, PassMove, ResignMove> &&move) noexcept
      : Command{id, "play"}, move{move} {};
  constexpr explicit PlayCommand(std::variant<VertexMove, PassMove, ResignMove> &&move) noexcept
      : Command{std::nullopt, "play"}, move{move} {};
  constexpr explicit PlayCommand() noexcept : Command{std::nullopt, "play"}, move{PassMove{}} {};
  constexpr explicit PlayCommand(const unsigned int id) noexcept : Command{id, "play"}, move{PassMove{}} {};
};

template <class... Ts> struct overloaded : Ts... { using Ts::operator()...; };
template <class... Ts> overloaded(Ts...)->overloaded<Ts...>;

auto to_string(PlayCommand const &command) {
  return std::visit(
      overloaded{
          [command](VertexMove arg) { return to_string(static_cast<Command>(command)) + " " + to_string(arg) + '\n'; },
          [command](PassMove arg) { return to_string(static_cast<Command>(command)) + " " + std::string{to_string(arg)} + '\n'; },
          [command](ResignMove arg) { return to_string(static_cast<Command>(command)) + " " + std::string{to_string(arg)} + '\n'; },
      },
      command.move);
}
} // namespace Go::GoTextProtocol

#endif // PLAYCOMMAND_H
