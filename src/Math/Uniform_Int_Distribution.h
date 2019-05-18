// Original Code from llvm/libcxx

#ifndef GO_UNIFORM_INT_DISTRIBUTION
#define GO_UNIFORM_INT_DISTRIBUTION

#include <cmath>
#include <limits>

namespace Go {
template <unsigned long long _Xp, size_t _Rp> struct log2_imp {
  static constexpr const size_t value = _Xp & ((unsigned long long)(1) << _Rp) ? _Rp : Go::log2_imp<_Xp, _Rp - 1>::value;
};

template <unsigned long long _Xp> struct log2_imp<_Xp, 0> { static constexpr const size_t value = 0; };

template <size_t _Rp> struct log2_imp<0, _Rp> { static constexpr const size_t value = _Rp + 1; };

template <class _UIntType, _UIntType _Xp> struct log2 {
  static constexpr const size_t value = Go::log2_imp<_Xp, sizeof(_UIntType) * __CHAR_BIT__ - 1>::value;
};

template <class _Engine, class _UIntType> class independent_bits_engine {
public:
  // types
  typedef _UIntType result_type;

private:
  typedef typename _Engine::result_type _Engine_result_type;
  typedef typename std::conditional<sizeof(_Engine_result_type) <= sizeof(result_type), result_type, _Engine_result_type>::type
      _Working_result_type;

  _Engine &e_;
  size_t w_ = 0;
  size_t w0_ = 0;
  size_t n_ = 0;
  size_t n0_ = 0;
  _Working_result_type y0_ = 0;
  _Working_result_type y1_ = 0;
  _Engine_result_type mask0_ = 0;
  _Engine_result_type mask1_ = 0;

  static constexpr const _Working_result_type _Rp = _Engine::max() - _Engine::min() + _Working_result_type(1);

  static constexpr const size_t m = Go::log2<_Working_result_type, _Rp>::value;
  static constexpr const size_t _WDt = std::numeric_limits<_Working_result_type>::digits;
  static constexpr const size_t _EDt = std::numeric_limits<_Engine_result_type>::digits;

public:
  // constructors and seeding functions
  constexpr independent_bits_engine(_Engine &e, size_t w) : e_(e), w_(w) {
    n_ = w_ / m + (w_ % m != 0);
    w0_ = w_ / n_;
    if (_Rp == 0)
      y0_ = _Rp;
    else if (w0_ < _WDt)
      y0_ = (_Rp >> w0_) << w0_;
    else
      y0_ = 0;
    if (_Rp - y0_ > y0_ / n_) {
      ++n_;
      w0_ = w_ / n_;
      if (w0_ < _WDt)
        y0_ = (_Rp >> w0_) << w0_;
      else
        y0_ = 0;
    }
    n0_ = n_ - w_ % n_;
    if (w0_ < _WDt - 1)
      y1_ = (_Rp >> (w0_ + 1)) << (w0_ + 1);
    else
      y1_ = 0;
    mask0_ = w0_ > 0 ? _Engine_result_type(~0) >> (_EDt - w0_) : _Engine_result_type(0);
    mask1_ = w0_ < _EDt - 1 ? _Engine_result_type(~0) >> (_EDt - (w0_ + 1)) : _Engine_result_type(~0);
  };

  // generating functions
  constexpr result_type operator()() { return eval(std::integral_constant<bool, _Rp != 0>()); }

private:
  constexpr result_type eval(std::false_type) { return static_cast<result_type>(e_() & mask0_); };
  constexpr result_type eval(std::true_type) {
    const size_t _WRt = std::numeric_limits<result_type>::digits;
    result_type _Sp = 0;
    for (size_t k = 0; k < n0_; ++k) {
      _Engine_result_type u;
      do {
        u = e_() - _Engine::min();
      } while (u >= y0_);
      if (w0_ < _WRt)
        _Sp <<= w0_;
      else
        _Sp = 0;
      _Sp += u & mask0_;
    }
    for (size_t k = n0_; k < n_; ++k) {
      _Engine_result_type u;
      do {
        u = e_() - _Engine::min();
      } while (u >= y1_);
      if (w0_ < _WRt - 1)
        _Sp <<= w0_ + 1;
      else
        _Sp = 0;
      _Sp += u & mask1_;
    }
    return _Sp;
  };
};

constexpr int clz(unsigned x) { return __builtin_clz(x); }

template <class _IntType = int> class uniform_int_distribution {
public:
  // types
  typedef _IntType result_type;

  class param_type {
    result_type a_;
    result_type b_;

  public:
    typedef uniform_int_distribution distribution_type;

    constexpr explicit param_type(result_type a = 0, result_type b = std::numeric_limits<result_type>::max()) : a_(a), b_(b) {}

    constexpr result_type a() const { return a_; }
    constexpr result_type b() const { return b_; }

    friend bool operator==(const param_type &x, const param_type &y) { return x.a_ == y.a_ && x.b_ == y.b_; }
    friend bool operator!=(const param_type &x, const param_type &y) { return !(x == y); }
  };

private:
  param_type p_;

public:
  // constructors and reset functions
  constexpr explicit uniform_int_distribution(result_type a = 0, result_type b = std::numeric_limits<result_type>::max())
      : p_(param_type(a, b)) {}
  constexpr explicit uniform_int_distribution(const param_type &p) : p_(p) {}
  constexpr void reset() {}

  // generating functions
  template <class _URNG> constexpr result_type operator()(_URNG &g) { return (*this)(g, p_); }
  template <class _URNG> constexpr result_type operator()(_URNG &g, const param_type &p) {
    typedef typename std::conditional<sizeof(result_type) <= sizeof(uint32_t), uint32_t, uint64_t>::type _UIntType;
    const _UIntType _Rp = _UIntType(p.b()) - _UIntType(p.a()) + _UIntType(1);
    if (_Rp == 1)
      return p.a();
    const size_t _Dt = std::numeric_limits<_UIntType>::digits;
    typedef Go::independent_bits_engine<_URNG, _UIntType> _Eng;
    if (_Rp == 0)
      return static_cast<result_type>(_Eng(g, _Dt)());
    size_t w = _Dt - clz(_Rp) - 1;
    if ((_Rp & (std::numeric_limits<_UIntType>::max() >> (_Dt - w))) != 0)
      ++w;
    _Eng e(g, w);
    _UIntType u = 0;
    do {
      u = e();
    } while (u >= _Rp);
    return static_cast<result_type>(u + p.a());
  };

  // property functions
  constexpr result_type a() const { return p_.a(); }
  constexpr result_type b() const { return p_.b(); }

  constexpr param_type param() const { return p_; }
  constexpr void param(const param_type &p) { p_ = p; }

  constexpr result_type min() const { return a(); }
  constexpr result_type max() const { return b(); }

  friend bool operator==(const uniform_int_distribution &x, const uniform_int_distribution &y) { return x.p_ == y.p_; }
  friend bool operator!=(const uniform_int_distribution &x, const uniform_int_distribution &y) { return !(x == y); }
};

} // namespace Go

#endif // GO_UNIFORM_INT_DISTRIBUTION
