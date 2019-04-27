#include "StrasbourgEngine.h"
#include "CommandExtractor.h"
#include <string>
#include <string_view>

using namespace Go::GoTextProtocol;

auto unknown_command_response(const Command &command) noexcept {
  if (command.id.has_value()) {
    return std::string{"?" + std::to_string(command.id.value()) + " unknown command"};
  } else {
    return std::string{"? unknown command"};
  }
}

auto Go::GoTextProtocol::Engine::StrasbourgEngine::run(std::string_view view) noexcept -> std::string {
  view = view.substr(0, view.find_first_of("#\n"));
  auto command = Go::GoTextProtocol::Util::extractCommand(view);

  return unknown_command_response(command);
}
