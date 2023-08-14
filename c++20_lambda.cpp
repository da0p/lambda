#include <iostream>
#include <variant>
#include <vector>

// overloading pattern
template<typename... Ts>
struct Overloading : Ts...
{
  using Ts::operator()...;
};

template<typename... Ts>
Overloading(Ts...) -> Overloading<Ts...>;

int
main()
{
  // Overloading
  std::vector<std::variant<int, std::string, double>> values{1, "Hello", 4.2};

  for(auto const& v : values) {
    std::visit(
      Overloading(
        [](int v) { std::cout << "v (int) = " << v << "\n"; },
        [](std::string const& v) { std::cout << "v (string) = " << v << "\n"; },
        [](double v) { std::cout << "v (double) = " << v << "\n"; }
      ),
      v
    );
  }

  // template lambda
  auto foo = [](auto x, auto y) { std::cout << x << ", " << y << "\n"; };
  auto bar = []<typename T, typename U>(T x, U y) {
    std::cout << x << ", " << y << "\n";
  };

  // default constructible lambda
  auto soFoo = [](int x, int y) { std::cout << x << ", " << y << "\n"; };
  decltype(soFoo) soBar;
}