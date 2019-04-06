#ifndef KOMICOMMAND_H
#define KOMICOMMAND_H

#include "Command.h"
#include <optional>

namespace Go::GoTextProtocol {

    struct KomiCommand : public Command {
        float new_komi = 0;
        constexpr explicit KomiCommand(const unsigned int id, const float new_komi) noexcept : Command({id, "komi"}), new_komi{new_komi} {};
        constexpr explicit KomiCommand(const float new_komi) noexcept: Command({std::nullopt, "komi"}), new_komi{new_komi} {};
    };

	auto to_string(KomiCommand const & command){
		return to_string(static_cast<Command>(command)) + " " + to_string(command.new_komi) + '\n';
	}
} // namespace Go::GoTextProtocol


#endif //KOMICOMMAND_H
