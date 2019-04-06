#ifndef BOARDSIZECOMMAND_H
#define BOARDSIZECOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct BoardSizeCommand : public Command {
        unsigned int size = 0;
        constexpr explicit BoardSizeCommand(const unsigned int id, const unsigned int size) noexcept : Command({id, "boardsize"}), size{size} {};
        constexpr explicit BoardSizeCommand(const unsigned int size) noexcept : Command({std::nullopt, "boardsize"}), size{size} {};
    };

	auto to_string(BoardSizeCommand const & command){
		return to_string(static_cast<Command>(command)) + " " + std::to_string(command.size) + '\n';
	}
} // namespace Go::GoTextProtocol


#endif //BOARDSIZECOMMAND_H
