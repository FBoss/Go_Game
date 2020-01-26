#include "gtest/gtest.h"

#include "GameEngine/StrassbourgEngine.h"

using namespace Go;
using namespace Go::GameEngine;

class GameEngineVerification : public ::testing::Test {
protected:
  StrassbourgEngine mStrassbourgEngine{};

  Go::GameEngine::GameEngine<Go::GameEngine::StrassbourgEngine> &mEngine = mStrassbourgEngine;
};
