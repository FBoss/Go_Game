#ifndef FINALSTATUSLISTCOMMAND_H
#define FINALSTATUSLISTCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go ::GoTextProtocol{

    enum class GameStatus{
        alive,
        seki,
        dead
    };

    struct FinalStatusListCommand : public Command {
        GameStatus status;
        constexpr explicit FinalStatusListCommand(const unsigned int id, const GameStatus status) noexcept: Command({id, "final_status_list"}), status{status}  {};
        constexpr explicit FinalStatusListCommand(const GameStatus status) noexcept: Command({std::nullopt, "final_status_list"}), status{status} {};
    };

    auto to_string(GameStatus const & status){
        switch(status){
            case GameStatus::alive:
                return std::string{"alive"};
            case GameStatus::dead:
                return std::string{"dead"};
            case GameStatus::seki:
                return std::string{"seki"};
        }
        return std::string{"to_string faild for GameStatus"};
    }

    auto to_string(FinalStatusListCommand const & command){
        return to_string(static_cast<Command>(command)) + " " + to_string(command.status) +'\n';
    }
} // namespace Go::GoTextProtocol


#endif //FINALSTATUSLISTCOMMAND_H
