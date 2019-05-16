#ifndef GO_CHISQUARED
#define GO_CHISQUARED

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

#include <functional>
#include <limits>

namespace Go {
constexpr auto e() noexcept {
  int steps = 20;
  double sum = 0;
  double divisor = 1;

  for (int i = 1; i < steps; ++i) {
    sum += 1.0 / divisor;
    divisor = divisor * i;
  }
  return sum;
}

/*
    constexpr auto sqrtNewtonRaphson(double x, double curr, double prev) noexcept -> double {
        return curr == prev
               ? curr
               : sqrtNewtonRaphson(x, 0.5 * (curr + x / curr), curr);
    }
*/
/*
 * Constexpr version of the square root
 * Return value:
 *   - For a finite and non-negative value of "x", returns an approximation for the square root of "x"
 *   - Otherwise, returns NaN
 */
/*
    double constexpr sqrt(double x)
    {
        return x >= 0 && x < std::numeric_limits<double>::infinity()
               ? sqrtNewtonRaphson(x, x, 0)
               : std::numeric_limits<double>::quiet_NaN();
    }
*/

/* Numerical integration method */
template <typename T> constexpr auto Simpson3_8(T function, double a, double b, int N) noexcept {
  double l1 = 0;
  const double h = (b - a) / N;
  const double h1 = h / 3.0;
  double sum = function(a) + function(b);

  for (int j = 3 * N - 1; j > 0; --j) {
    l1 = (j % 3) ? 3.0 : 2.0;
    sum += l1 * function(a + h1 * j);
  }

  return h * sum / 8.0;
}
/*
    constexpr auto exp(double value) noexcept -> double {
        if( value == 0){
            return 1;
        }
        if(value == 1){
            return e();
        }

        int steps = 26;
        double sum = 0;
        if(value == 0){
            return 1.0;
        }

        double divisor = 1;
        double dividend = 1;

        for(int i = 1; i < steps; ++i){
            sum += dividend / divisor;
            divisor = divisor * i;
            dividend = dividend * value;
        }

        return sum;
    }

    constexpr double pow( double base, double power, double precision = .000001) noexcept
    {
        if ( power < 0 ) return 1 / pow( base, -power, precision );
        if ( power >= 10 ) return sqrt( pow( base, power/2, precision/2 ) );
        if ( power >= 1 ) return base * pow( base, power-1, precision );
        if ( precision >= 1 ) return sqrt( base );
        return sqrt( pow( base, power*2, precision*2 ) );
    }
*/

inline auto Gamma_Spuge_Coefficient() noexcept {
  std::array<double, 12> coefficient{};
  coefficient.at(0) = sqrt(2.0 * M_PI);

  auto k1_factrl = 1.0;
  for (auto k = 1; k < coefficient.size(); k++) {
    coefficient.at(k) = exp(coefficient.size() - k) * pow(coefficient.size() - k, k - 0.5) / k1_factrl;
    k1_factrl *= -k;
  }

  return coefficient;
}

inline double Gamma_Spouge(double z) noexcept {
  auto coef = Gamma_Spuge_Coefficient();

  auto accum = coef.at(0);

  for (auto k = 1; k < coef.size(); k++) {
    accum += coef.at(k) / (z + k);
  }

  accum *= exp(-(z + coef.size())) * pow(z + coef.size(), z + 0.5);
  return accum / z;
}

constexpr double GammaIncomplete_Q(double a, double x) noexcept {
  const double h = 1.5e-2; /* approximate integration step size */
  ;

  /* this cuts off the tail of the integration to speed things up */
  auto y = a - 1;
  ;
  auto f0 = [](double t) noexcept { return exp(-t); };

  while ((f0(y) * (x - y) > 2.0e-8) && (y < x)) {
    y += .4;
  }
  if (y > x) {
    y = x;
  }

  return 1.0 - Simpson3_8(f0, 0, y, (int)(y / h)) / Gamma_Spouge(a);
}

template <typename T> constexpr auto chi2UniformDistance(const T &data) noexcept {
  double expected = 0.0;
  double sum = 0.0;

  for (auto &val : data) {
    expected += val;
  }

  expected /= data.size();

  for (auto &val : data) {
    double x = val - expected;
    sum += x * x;
  }

  return sum / expected;
}

constexpr double chi2Probability(int degree_of_freedom, double distance) noexcept {
  return GammaIncomplete_Q(0.5 * degree_of_freedom, 0.5 * distance);
}

template <typename T> constexpr auto chiIsUniform(const T &data, double significance = 0.05) noexcept {
  int degree_of_freedom = data.size() - 1;
  auto dist = chi2UniformDistance(data);
  return chi2Probability(degree_of_freedom, dist) > significance;
}

} // namespace Go

#endif // GO_CHISQUARED
