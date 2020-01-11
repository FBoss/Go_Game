#include "GtpEngine/Engine.h"

#include <tuple>

namespace Go::GoTextProtocol {

struct GtpPrinter : public GtpEngine<GtpPrinter, int, int> {
  std::string name() { return "GtpPrinter"; }

  std::string version() { return ""; }

  std::string komi(float) { return ""; }

  std::tuple<std::string, ResponseType> boardsize(int size) { return {"", ResponseType::success}; }
};

} // namespace Go::GoTextProtocol

using namespace Go::GoTextProtocol;

int main() {
  GtpPrinter engine = GtpPrinter{};

  bool running = true;

  while (running) {
    std::string input{};
    std::getline(std::cin, input);
    auto response = engine.executeCommand(input);

    std::cout << response;
    running = not response.exit_after_response;
  }

  return 0;
}
