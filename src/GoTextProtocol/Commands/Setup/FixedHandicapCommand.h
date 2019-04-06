#ifndef FIXEDHANDICAPCOMMAND_H
#define FIXEDHANDICAPCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct FixedHandicapCommand : public Command {
        int number_of_stones = 0;
        constexpr explicit FixedHandicapCommand(const unsigned int id, const int number_of_stones) noexcept : Command({id, "fixed_handicap"}), number_of_stones{number_of_stones} {};
        constexpr explicit FixedHandicapCommand(const int number_of_stones) noexcept : Command({std::nullopt, "fixed_handicap"}), number_of_stones{number_of_stones} {};
    };


    auto to_string(FixedHandicapCommand const & command){
        return to_string(static_cast<Command>(command)) + " " + std::to_string(command.number_of_stones) + '\n';
    }
} // namespace Go::GoTextProtocol


#endif //FINALSCORECOMMAND_H
