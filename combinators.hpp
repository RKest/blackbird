
#pragma once

#include <cmath>
#include <functional>

namespace combinators {

/////////////////
// combinators //
/////////////////

// I (no bird name)
constexpr auto _id = std::identity{};

// B (The Bluebird)
constexpr auto _b = [](auto f, auto g) { return [=](auto x) { return f(g(x)); }; };

// BB (The Bluebird^2)
constexpr auto _bb = [](auto f, auto g, auto h) { return [=](auto x) { return f(g(h(x))); }; };

// BBB (The Bluebird^3)
constexpr auto _bbb = [](auto f, auto g, auto h, auto i) { return [=](auto x) { return f(g(h(i(x)))); }; };

// B1 (The Blackbird)
constexpr auto _b1 = [](auto f, auto g) { return [=](auto x, auto y) { return f(g(x, y)); }; };

// C (The Cardinal) aka `flip` in Haskell
constexpr auto _c = [](auto f) { return [=](auto x, auto y) { return f(y, x); }; };

// D2 (The Dovekie)
constexpr auto _d2_ = [](auto f, auto g, auto h) { return [=](auto x, auto y) { return g(f(x), h(y)); }; };

// K (Kestrel)
constexpr auto _l_ = [](auto x, auto y) { return x; };

// KI
constexpr auto _r_ = [](auto x, auto y) { return y; };

// Phi (The Phoenix)
constexpr auto _phi = [](auto f, auto g, auto h) { return [=](auto x) { return g(f(x), h(x)); }; };

// Phi1 (The Pheasant)
constexpr auto _phi1_ = [](auto f, auto g, auto h) { return [=](auto x, auto y) { return g(f(x, y), h(x, y)); }; };

// Psi (The Psi Bird)
constexpr auto _psi = [](auto f, auto g) { return [=](auto x, auto y) { return f(g(x), g(y)); }; };

// W (The Warbler)
constexpr auto _w = [](auto f) { return [=](auto x) { return f(x, x); }; };

/////////////////////////////////////////////
// more convenient binary/unary operations //
/////////////////////////////////////////////

constexpr auto _eq    = [](auto x) { return [x](auto y) { return x == y; }; };
constexpr auto _eq_   = std::equal_to{};
constexpr auto _neq_  = std::not_equal_to{};
constexpr auto _lt    = [](auto x) { return [x](auto y) { return x > y; }; };
constexpr auto lt_    = [](auto x) { return [x](auto y) { return y < x; }; };
constexpr auto _lt_   = std::less{};
constexpr auto _lte_  = std::less_equal{};
constexpr auto _gt_   = std::greater{};
constexpr auto _gte   = [](auto x) { return [x](auto y) { return x >= y; }; };
constexpr auto _gte_  = std::greater_equal{};
constexpr auto _plus  = [](auto x) { return [x](auto y) { return x + y; }; };
constexpr auto _plus_ = std::plus{};
constexpr auto _mul   = [](auto x) { return [x](auto y) { return x * y; }; };
constexpr auto _mul_  = std::multiplies{};
constexpr auto _sub   = [](auto x) { return [x](auto y) { return x - y; }; };
constexpr auto sub_   = [](auto x) { return [x](auto y) { return y - x; }; };
constexpr auto _sub_  = std::minus{};
constexpr auto _mod   = [](auto x) { return [x](auto y) { return x % y; }; };
constexpr auto mod_   = [](auto x) { return [x](auto y) { return y % x; }; };
constexpr auto _mod_  = std::modulus{};
constexpr auto _pow_  = [](auto x, auto y) { return std::pow(x, y); };
constexpr auto _div   = [](auto x) { return [x](auto y) { return x / y; }; };
constexpr auto div_   = [](auto x) { return [x](auto y) { return y / x; }; };
constexpr auto _div_  = std::divides{};
constexpr auto _or_   = std::logical_or{};
constexpr auto _and_  = std::logical_and{};
constexpr auto _neg   = std::negate{};
constexpr auto _not   = std::logical_not{};
constexpr auto _sign  = [](auto x) { return x > 0 ? 1 : x < 0 ? -1 : 0; };
constexpr auto _sqrt  = [](auto x) { return std::sqrt(x); };
constexpr auto _min_  = [](auto x, auto y) { return std::min(x, y); };
constexpr auto _max_  = [](auto x, auto y) { return std::max(x, y); };

// conversions
constexpr auto _int    = [](auto x) { return static_cast<int>(x); };
constexpr auto _uint   = [](auto x) { return static_cast<unsigned int>(x); };
constexpr auto _bool   = [](auto x) { return static_cast<bool>(x); };
constexpr auto _float  = [](auto x) { return static_cast<float>(x); };
constexpr auto _double = [](auto x) { return static_cast<double>(x); };

template <int N>
constexpr auto _nth = [](auto t) { return std::get<N>(t); };
constexpr auto _fst = [](auto t) { return std::get<0>(t); };
constexpr auto _snd = [](auto t) { return std::get<1>(t); };

constexpr auto _rshift_  = [](auto x, auto y) { return x >> y; };
constexpr auto _bit_and_ = std::bit_and{};
constexpr auto _bit_xor_ = std::bit_xor{};

constexpr auto _odd  = [](auto x) { return (x % 2) == 1; };
constexpr auto _even = [](auto x) { return (x % 2) == 0; };

}  // namespace combinators
