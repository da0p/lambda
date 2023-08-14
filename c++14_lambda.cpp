#include <functional>
#include <iostream>
#include <memory>

template<typename T>
auto
sum(T x)
{
  return x;
}

template<typename T1, typename... T>
auto
sum(T1 s, T... ts)
{
  return s + sum(ts...);
}

int
main()
{
  // default parameters
  auto f = [](int a, int b = 10) { std::cout << "a + b = " << a + b << "\n"; };
  f(20);

  // return type deduction
  auto x = [](int a, float b) { return a + b; };

  // capture with an initializer
  int a = 30;
  int b = 12;

  auto const foo = [z = a + b]() { std::cout << z << "\n"; };
  foo();

  std::unique_ptr<int> p(new int{10});
  auto const bar = [ptr = std::move(p)] {
    std::cout << "pointer in lambda: " << ptr.get() << "\n";
  };
  std::cout << "pointer in main(): " << p.get() << "\n";
  bar();

  // remember that having a only-movable variable makes bar not copyable object
  // Error since std::function only accepts copyable object
  // std::function<void(void)> fx = [ptr = std::move(p)] {
  //  std::cout << "no way to compile";
  // };

  // Generic lambda
  auto const generic_foo = [](auto x, int y) {
    std::cout << x << ", " << y << "\n";
  };
  generic_foo(42, 1);
  generic_foo(4.2, 10);
  generic_foo("hello", 42);

  // variadic generic arguments with lambda
  auto const sumAll = [](auto... args) {
    std::cout << "sum of: " << sizeof...(args) << " numbers\n";
    return sum(args...);
  };
  std::cout << "sumAll = " << sumAll(1, 2, 3.0, 4.2) << "\n";

  // recursive lambda, with generic lambda, the generic parameter is resolved
  // to the correct type
  auto const recursive_fact = [](int n) noexcept {
    auto const f_impl = [](int n, auto const& impl) noexcept -> int {
      return n > 1 ? n * impl(n - 1, impl) : 1;
    };
    return f_impl(n, f_impl);
  };

  std::cout << "factorial(10) = " << recursive_fact(10) << "\n";
}