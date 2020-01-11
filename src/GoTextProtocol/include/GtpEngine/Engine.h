#include <algorithm>
#include <charconv>
#include <iostream>
#include <iterator>
#include <optional>
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

namespace Go::GoTextProtocol {

enum class ResponseType { success = '=', failure = '?' };

struct GtpResponse {
  std::optional<int> id;
  std::string message;
  ResponseType type;
  bool exit_after_response;

  friend std::ostream &operator<<(std::ostream &, const GtpResponse &);
  friend bool exitAfterMessage(const GtpResponse &response);
};

std::ostream &operator<<(std::ostream &out, const GtpResponse &response) {
  out << static_cast<char>(response.type);
  if (response.id.has_value()) {
    out << response.id.value();
  }
  if (response.message.size() > 0) {
    out << " " << response.message;
  }
  out << "\n\n";

  return out;
}

template <typename Engine, typename BlackPlayer, typename WhitePlayer> class GtpEngine {
public:
  GtpResponse executeCommand(std::string command) noexcept {

    std::istringstream iss{command};
    std::vector<std::string> results(std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>());

    std::optional<int> id = std::nullopt;

    {
      int tempId;

      if (auto [p, ec] = std::from_chars(results.front().data(), results.front().data() + results.front().size(), tempId);
          ec == std::errc()) {
        id = tempId;
        results.erase(results.begin());
      }
    }

    if (results.size() > 0) {
      const auto command_string = results.front();
      results.erase(results.begin());

      if ("protocol_version" == command_string) {
        return {id, "2", ResponseType::success, false};
      } else if ("name" == command_string) {
        return {id, static_cast<Engine &>(*this).name(), ResponseType::success, false};
      } else if ("version" == command_string) {
        return {id, static_cast<Engine &>(*this).version(), ResponseType::success, false};
      } else if ("known_command" == command_string) {
        const auto iterator = std::find(known_commands.begin(), known_commands.end(), results.front());

        if (iterator != known_commands.end()) {
          return {id, "true", ResponseType::success, false};
        }
        return {id, "false", ResponseType::success, false};
      } else if ("list_commands" == command_string) {
        std::string list{};
        for (const auto &val : known_commands) {
          list = list + val + "\n";
        }

        return {id, list, ResponseType::success, false};
      } else if ("boardsize" == command_string) {
        if (results.size() == 1) {
          int size;

          if (auto [p, ec] = std::from_chars(results.front().data(), results.front().data() + results.front().size(), size);
              ec == std::errc()) {
            const auto [text, type] = static_cast<Engine &>(*this).boardsize(size);
            return {id, text, type, false};
          }
        }

        return {id, "syntax error", ResponseType::failure, false};
      } else if ("clear_board" == command_string) {
        return {id, "", ResponseType::success, false};
      } else if ("quit" == command_string) {
        return {id, "", ResponseType::success, true};
      } else if ("komi" == command_string) {
        if (results.size() != 1) {
          return {id, "syntax error", ResponseType::failure, false};
        }

        float komi = 0;
        try {
          komi = std::stof(results.front());
        } catch (std::exception &) {
          return {id, "syntax error", ResponseType::failure, false};
        }

        return {id, static_cast<Engine &>(*this).komi(komi), ResponseType::success, false};
      } else if ("play" == command_string) {

      }

      else if ("genmove" == command_string) {
      }
    }

    return {id, "unknown command", ResponseType::failure, false};
  }

protected:
  BlackPlayer blackPlayer;
  WhitePlayer whitePlayer;

private:
  const std::vector<std::string> known_commands{"protocol_version", "name", "version", "known_command", "list_commands", "boardsize",
                                                "clear_board",      "quit", "komi",    "play",          "genmove"};
};

} // namespace Go::GoTextProtocol
