#include "GameEngine/StrassbourgEngine.h"
#include "GtpEngine/Engine.h"

#include "player/random.h"

#include <fstream>
#include <tuple>

namespace Go::GoTextProtocol {

struct GtpPrinter : public GtpEngine<GtpPrinter, Go::GameEngine::StrassbourgEngine,
                                     Go::GameEngine::Player::RandomPlayer<Go::GameEngine::StrassbourgEngine>> {
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

  std::ofstream outfile;
  outfile.open("commands.txt");

  while (running) {
    std::string input{};
    std::getline(std::cin, input);

    // input = "play black J8";

    outfile << input << '\n';

    std::cout << "command: " << input << '\n';
    auto response = engine.executeCommand(input);

    outfile << response;
    outfile.flush();
    std::cout << response;
    running = not response.exit_after_response;
  }

  return 0;
}
