#ifndef PLACEFREEHANDICAPCOMMAND_H
#define PLACEFREEHANDICAPCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct PlaceFreeHandicapCommand : public Command {
        int number_of_stones = 0;
        constexpr explicit PlaceFreeHandicapCommand(unsigned int id, const int number_of_stones) noexcept : Command({id, "place_free_handicap"}), number_of_stones{number_of_stones} {};
        constexpr explicit PlaceFreeHandicapCommand(const int number_of_stones) noexcept : Command({std::nullopt, "place_free_handicap"}), number_of_stones{number_of_stones} {};
    };

	auto to_string(PlaceFreeHandicapCommand const & command){
		return to_string(static_cast<Command>(command)) + " " + std::to_string(command.number_of_stones) + '\n';
	}

} // namespace Go::GoTextProtocol


#endif //PLACEFREEHANDICAPCOMMAND_H
