#ifndef CLEARBOARDCOMMAND_H
#define CLEARBOARDCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct ClearBoardCommand : public Command {
        constexpr explicit ClearBoardCommand(unsigned int id) noexcept: Command({id, "clear_board"}) {};
        constexpr explicit ClearBoardCommand() noexcept: Command({std::nullopt, "clear_board"}) {};
    };


    auto to_string(ClearBoardCommand const & command){
        return to_string(static_cast<Command>(command)) + '\n';
    }
} // namespace Go::GoTextProtocol


#endif //CLEARBOARDCOMMAND_H
