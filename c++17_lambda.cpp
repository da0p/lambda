#include <array>
#include <chrono>
#include <functional>
#include <future>
#include <iostream>
#include <thread>
#include <tuple>
#include <variant>

/// Constexpr lambda example
template<typename Range, typename Func, typename T>
constexpr T
SumAll(Range&& range, Func func, T init)
{
  for(auto&& elem : range) {
    init += func(elem);
  }
  return init;
}

template<size_t N>
constexpr auto
Factorial()
{
  return N * Factorial<N - 1>();
}

template<>
constexpr auto
Factorial<1>()
{
  return 1;
}

template<size_t N, typename Func>
constexpr auto
WeirdFactorial(Func func)
{
  return Factorial<N>() * func();
}

/// Capture *this
struct LongLife
{
  int value;

  void print() const { std::cout << "value = " << value << "\n"; }
  auto execute()
  {
    return [*this] {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));
      print();
    };
  }
  ~LongLife()
  {
    std::cout << "Long live, the King!"
              << "\n";
  }
};

int
main()
{
  constexpr std::array arr{1, 2, 3, 4};

  constexpr auto sum = SumAll(
    arr, [](auto i) { return i * i; }, 0
  );
  static_assert(sum == 30);

  constexpr auto fact = WeirdFactorial<5>([]() { return 2; });
  static_assert(fact == 240);

  std::thread t;
  {
    LongLife longLifeObj{42};
    t = std::thread([&longLifeObj] { longLifeObj.execute()(); });
  }
  t.join();

  // std::invoke
  [](auto x) { std::cout << "x = " << x << "\n"; }(42);
  std::invoke([](auto x) { std::cout << "x = " << x << "\n"; }, 42);

  std::tuple x{1, 2, 3, "Hello"};
  std::apply([](auto... args) { ((std::cout << args << " "), ...); }, x);
}