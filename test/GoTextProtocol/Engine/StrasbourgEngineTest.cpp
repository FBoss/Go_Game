#include "gtest/gtest.h"
#include <GenMoveCommand.h>

#include "StrasbourgEngine.h"

namespace {
TEST(StrasbourgEngine, empty) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("");
  EXPECT_EQ("? unknown command", value);
}

TEST(StrasbourgEngine, bogusWithoutId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("asdgasd");
  EXPECT_EQ("? unknown command", value);
}

TEST(StrasbourgEngine, bogusWhithId) {
  Go::GoTextProtocol::Engine::StrasbourgEngine engine{};
  auto value = engine.run("1234 asdgasd");
  EXPECT_EQ("?1234 unknown command", value);
}

} // namespace