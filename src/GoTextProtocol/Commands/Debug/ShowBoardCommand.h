#ifndef SHOWBOARDCOMMAND_H
#define SHOWBOARDCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct ShowBoardCommand : public Command {
        constexpr explicit ShowBoardCommand(unsigned int id) noexcept: Command({id, "showboard"}) {};
        constexpr explicit ShowBoardCommand() noexcept: Command({std::nullopt, "showboard"}) {};
    };

	auto to_string(ShowBoardCommand const & command){
		return to_string(static_cast<Command>(command)) +'\n';
	}
} // namespace Go::GoTextProtocol


#endif //SHOWBOARDCOMMAND_H
