#ifndef GO_RANDOM
#define GO_RANDOM

#include <limits>

namespace Go {

class Linear_congruential_generator {
public:
  using result_type = uint64_t;
  constexpr auto operator()() noexcept -> result_type {
    mState = (mMultiplier_A * mState + mIncrement_C);
    return mState;
  }

  constexpr result_type min() { return std::numeric_limits<result_type>::min(); }
  constexpr result_type max() { return std::numeric_limits<result_type>::max(); }

private:
  uint64_t mState = 0;
  const uint64_t mMultiplier_A = 6364136223846793005;
  const uint64_t mIncrement_C = 1442695040888963407;
};
} // namespace Go

#endif // GO_RANDOM
