#include "StrasbourgEngine.h"

#include <iostream>
#include <string>

int main() {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};

  std::string input;
  std::string output;

  while (true) {
    std::getline(std::cin, input);
    output = engine.run(input);
    if (output.find(" quit") != std::string::npos) {
      break;
    }
    std::cout << output;
  }
}