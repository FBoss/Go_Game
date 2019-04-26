#ifndef COMMANDMOVE_H
#define COMMANDMOVE_H

#include "Stone.h"
#include "Vertex.h"
#include "GTPStoneUtils.h"

namespace Go::GoTextProtocol {
struct Move {};

struct VertexMove : Move {
  Stone color;
  Vertex vertex;
};

struct PassMove : Move {
  std::string_view pass = "pass";
};

struct ResignMove : Move {
  std::string_view resign = "resign";
};

auto to_string(VertexMove const &move) { return std::string{to_string(move.color)} + " " + to_string(move.vertex); }

constexpr auto to_string(PassMove const &move) noexcept { return move.pass; }

constexpr auto to_string(ResignMove const &move) noexcept { return move.resign; }
} // namespace Go::GoTextProtocol

#endif // COMMANDMOVE_H
