#ifndef TIMESETTINGSCOMMAND_H
#define TIMESETTINGSCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct TimeSettingsCommand : public Command {
        unsigned int main_time = 0;
        unsigned int byo_yomi_time = 0;
        unsigned int byo_yomi_stones = 0;
        constexpr explicit TimeSettingsCommand(const unsigned int id, const unsigned int main_time, const unsigned int byo_yomi_time, const unsigned int byo_yomi_stones) noexcept : Command({id, "time_settings"}), main_time{main_time}, byo_yomi_time{byo_yomi_time}, byo_yomi_stones{byo_yomi_stones} {};
        constexpr explicit TimeSettingsCommand(const unsigned int main_time, const unsigned int byo_yomi_time, const unsigned int byo_yomi_stones) noexcept: Command({std::nullopt, "time_settings"}), main_time{main_time}, byo_yomi_time{byo_yomi_time}, byo_yomi_stones{byo_yomi_stones}   {};
    };

    auto to_string(TimeSettingsCommand const & command){
        return to_string(static_cast<Command>(command)) + " " + std::to_string(command.main_time) + " " + std::to_string(command.byo_yomi_time) + " " + std::to_string(command.byo_yomi_stones) +'\n';
    }
} // namespace Go::GoTextProtocol


#endif //TIMESETTINGSCOMMAND_H
