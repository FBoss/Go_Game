#include "gtest/gtest.h"

#include "CommandExtractor.h"

using namespace Go::GoTextProtocol::Util;

namespace {

TEST(CommandExtractor, empty) {
  auto value = extractCommand("");
  EXPECT_EQ("", std::string{value.command.data()});
  EXPECT_EQ(std::nullopt, value.id);
}

TEST(CommandExtractor, number_only) {
  auto value = extractCommand("2645");
  EXPECT_EQ("", std::string{value.command.data()});
  EXPECT_EQ(2645, value.id);
}

TEST(CommandExtractor, command_only) {
  auto value = extractCommand("command");
  EXPECT_EQ("command", std::string{value.command.data()});
  EXPECT_EQ(std::nullopt, value.id);
}

TEST(CommandExtractor, number_and_command) {
  auto value = extractCommand("257 command");
  EXPECT_EQ("command", std::string{value.command.data()});
  EXPECT_EQ(257, value.id);
}

TEST(CommandExtractor, zero_and_command) {
  auto value = extractCommand("0 command");
  EXPECT_EQ("command", std::string{value.command.data()});
  EXPECT_EQ(0, value.id);
}

TEST(CommandExtractor, multi_word) {
  auto value = extractCommand("command 0 word1 word2 word 3");
  EXPECT_EQ("command", std::string{value.command.data()});
  EXPECT_EQ(std::nullopt, value.id);
}

} // namespace