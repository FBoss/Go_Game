#include "gtest/gtest.h"
#include <GenMoveCommand.h>

#include "StrasbourgEngine.h"

namespace {

TEST(StrasbourgEngine, empty) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("");
  EXPECT_EQ("? unknown command\n\n", value);
}

TEST(StrasbourgEngine, bogusWithoutId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("asdgasd");
  EXPECT_EQ("? unknown command\n\n", value);
}

TEST(StrasbourgEngine, bogusWhithId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("1234 asdgasd");
  EXPECT_EQ("?1234 unknown command\n\n", value);
}

TEST(StrasbourgEngine, NameCommandWithoutId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("name");
  EXPECT_EQ("= HSLU Strasbourg Engine\n\n", value);
}

TEST(StrasbourgEngine, NameCommandWithId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("1234 name");
  EXPECT_EQ("=1234 HSLU Strasbourg Engine\n\n", value);
}

TEST(StrasbourgEngine, ProtocolVersionCommandWithoutId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("protocol_version");
  EXPECT_EQ("= 2\n\n", value);
}

TEST(StrasbourgEngine, ProtocolVersionCommandWithId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("1234 protocol_version");
  EXPECT_EQ("=1234 2\n\n", value);
}

TEST(StrasbourgEngine, VersionCommandWithoutId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("version");
  EXPECT_EQ("= 1.0\n\n", value);
}

TEST(StrasbourgEngine, VersionCommandWithId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("1234 version");
  EXPECT_EQ("=1234 1.0\n\n", value);
}

TEST(StrasbourgEngine, ListCommandsCommandWithId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("1234 list_commands");
  EXPECT_EQ(std::string{"=1234 name\nprotocol_version\nversion\nlist_commands\n\n"}, value);
}

TEST(StrasbourgEngine, ListCommandsCommandWithoutId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("list_commands");
  EXPECT_EQ(std::string{"= name\nprotocol_version\nversion\nlist_commands\n\n"}, value);
}

} // namespace