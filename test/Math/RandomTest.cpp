#include "gtest/gtest.h"

#include <random>

#include "ChiSquared.h"
#include "Random.h"
#include "Uniform_Int_Distribution.h"

namespace {

TEST(Linear_congruential_generator, run_with_std_uniform_distribution) {
  const auto nrolls = 10 * 100; // number of experiments

  // std::default_random_engine generator;
  Go::Linear_congruential_generator generator;
  std::uniform_int_distribution<int> distribution(0, 9);

  std::array<int, 10> p{};

  for (int i = 0; i < nrolls; ++i) {
    int number = distribution(generator);
    ++p.at(number);
  }

  EXPECT_TRUE(Go::chiIsUniform(p));
}

TEST(uniform_int_distribution, 0_9) {
  const auto nrolls = 10 * 100; // number of experiments

  std::default_random_engine generator;
  Go::uniform_int_distribution<int> distribution(0, 9);

  std::array<int, 10> p{};

  for (int i = 0; i < nrolls; ++i) {
    int number = distribution(generator);
    ++p.at(number);
  }

  EXPECT_TRUE(Go::chiIsUniform(p));
}

TEST(uniform_int_distribution, 19x19) {
  const auto nrolls = 19 * 19 * 100; // number of experiments

  std::default_random_engine generator;
  Go::uniform_int_distribution<int> distribution(0, 19 * 19 - 1);

  std::array<int, 19 * 19> p{};

  for (int i = 0; i < nrolls; ++i) {
    int number = distribution(generator);
    ++p.at(number);
  }

  EXPECT_TRUE(Go::chiIsUniform(p));
}

TEST(random, constexpr_test) {
  constexpr const auto nrolls = 10 * 100; // number of experiments

  constexpr auto output = []() {
    Go::Linear_congruential_generator generator;
    // std::default_random_engine generator;
    Go::uniform_int_distribution<int> distribution(0, 9);

    std::array<int, 10> p{};

    for (int i = 0; i < nrolls; ++i) {
      int number = distribution(generator);
      ++p.at(number);
    }
    return p;
  }();

  for (auto val : output) {
    EXPECT_EQ(val, 100);
  }
  // TODO: fix chiIsUniform function
  //EXPECT_TRUE(Go::chiIsUniform(output));
}

} // namespace
