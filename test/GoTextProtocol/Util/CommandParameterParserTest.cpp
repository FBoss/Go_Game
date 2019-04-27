#include "gtest/gtest.h"

#include "Command.h"
#include "CommandParameterParser.h"

namespace {

TEST(CommandParameterParser, nullopt) {
  const Go::GoTextProtocol::Command &command{std::nullopt, ""};
  auto value = Go::GoTextProtocol::Util::parse_parameter<Go::GoTextProtocol::Command>(command);
  EXPECT_EQ(value.id, std::nullopt);
  EXPECT_EQ(std::string{value.command.data()}, "");
}

TEST(CommandParameterParser, CopyIdvalue) {
  const Go::GoTextProtocol::Command &command{2345, "command"};
  auto value = Go::GoTextProtocol::Util::parse_parameter<Go::GoTextProtocol::Command>(command);
  EXPECT_EQ(value.id, 2345);
  EXPECT_EQ(std::string{value.command.data()}, "");
}

} // namespace
