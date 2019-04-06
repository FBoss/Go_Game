#ifndef LOADSGFCOMMAND_H
#define LOADSGFCOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct LoadSgfCommand : public Command {
        std::string_view file_name;
        unsigned int move_number = 0;
        constexpr explicit LoadSgfCommand(unsigned int id, std::string_view file, const unsigned int move_number) noexcept: Command({id, "loadsgf"}), file_name{file}, move_number{move_number} {};
        constexpr explicit LoadSgfCommand(std::string_view file, const unsigned int move_number) noexcept: Command({std::nullopt, "loadsgf"}), file_name{file}, move_number{move_number} {};
    };

    auto to_string(LoadSgfCommand const & command){
        return to_string(static_cast<Command>(command)) + " " + std::string{command.file_name} + " " + std::to_string(command.move_number)  +'\n';
    }
} // namespace Go::GoTextProtocol


#endif //LOADSGFCOMMAND_H
