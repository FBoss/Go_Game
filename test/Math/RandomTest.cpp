#include "gtest/gtest.h"

#include <random>

#include "ChiSquared.h"
#include "Random.h"

namespace {

TEST(Linear_congruential_generator, run_with_std_uniform_distribution) {
  const auto nrolls = 10000000; // number of experiments

  // std::default_random_engine generator;
  Go::Linear_congruential_generator generator;
  std::uniform_int_distribution<int> distribution(0, 999);

  std::array<int, 1000> p{};

  for (int i = 0; i < nrolls; ++i) {
    int number = distribution(generator);
    ++p.at(number);
  }

  EXPECT_TRUE(Go::chiIsUniform(p));
}

} // namespace
