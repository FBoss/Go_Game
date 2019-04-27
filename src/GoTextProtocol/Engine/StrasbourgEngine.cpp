#include "StrasbourgEngine.h"
#include "CommandExtractor.h"
#include <NameCommand.h>
#include <string>
#include <string_view>

using namespace Go::GoTextProtocol;

auto handle_command(NameCommand &command) noexcept { return std::string{"HSLU Strasbourg Engine"}; }

auto Go::GoTextProtocol::Engine::StrasbourgEngine::run(std::string_view view) noexcept -> std::string {
  view = view.substr(0, view.find_first_of("#\n"));
  auto command = Go::GoTextProtocol::Util::extractCommand(view);

  std::string id{};
  if (command.id.has_value()) {
    id = std::to_string(command.id.value());
  }

  if ("name" == std::string{command.command.data()}) {
    return std::string{"=" + id + " HSLU Strasbourg Engine"};
  }

  return std::string{"?" + id + " unknown command"};
}
