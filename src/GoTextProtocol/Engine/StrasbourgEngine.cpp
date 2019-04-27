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
  auto command_text = std::string{command.command.data()};

  std::string response{"?" + id + " unknown command"};

  if ("name" == command_text) {
    response = std::string{"=" + id + " HSLU Strasbourg Engine"};
  } else if ("protocol_version" == command_text) {
    response = std::string{"=" + id + " 2"};
  } else if ("version" == command_text) {
    response = std::string{"=" + id + " 1.0"};
  } else if ("list_commands" == command_text) {
    response = std::string{"=" + id + " name"};
    response.append("\nprotocol_version");
    response.append("\nversion");
    response.append("\nlist_commands");
  }

  return response + "\n\n";
}
