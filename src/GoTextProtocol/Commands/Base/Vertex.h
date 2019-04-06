#ifndef COMMANDVERTEX_H
#define COMMANDVERTEX_H

namespace Go::GoTextProtocol {

struct Vertex {
  unsigned int row = 0;
  unsigned int column = 0;
};

auto to_string(Vertex const &vertex) {
  std::string row;

  const char char_value = 65; // ASCII value of 'A'

  int row_value = vertex.row;
  bool first_run = true;

  do {
    if (!first_run) {
      --row_value;
    } else {
      first_run = false;
    }

    char digit = row_value % 25;
    row_value = row_value / 25;

    if (digit > 7) {
      ++digit;
    }

    row.insert(0, 1, char_value + digit);

  } while (row_value > 0);

  return row + std::string{std::to_string(vertex.column + 1)};
}
} // namespace Go::GoTextProtocol

#endif // COMMANDVERTEX_H
