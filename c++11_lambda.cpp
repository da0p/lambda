#include <iostream>
#include <type_traits>

struct BigBigChicken
{
  uint64_t value;
  uint64_t key;
};

int
main()
{
  // empty lambda
  auto x = [] {};

  // with parameters list
  auto y = [](int x, int ratio) { return x * ratio; };

  // trailing return type
  auto z = [](double x) -> int { return x; };

  // additional specifiers
  int k = 10;
  auto a = [k](int a) mutable noexcept {
    ++k;
    return a < k;
  };

  // optional parameters list
  auto b = [k] { std::cout << k; }; // no () need
                                    // auto c = [k] mutable {++k;};
  //  [] noexcept {};

  std::cout << "sizeof(x) = " << sizeof(x) << "\n";
  std::cout << "sizeof(y) = " << sizeof(y) << "\n";
  std::cout << "sizeof(a) = " << sizeof(a) << "\n";

  BigBigChicken bigChicken;
  auto c = [&bigChicken]() { std::cout << "I'm a big chicken\n"; };
  std::cout << "sizeof(bigChicken) = " << sizeof(bigChicken) << "\n";

  auto d =
    static_cast<int (*)(int, int)>([](int x, int ratio) { return x * ratio; });

  std::cout << "sizeof(d) = " << sizeof(d)
            << "\n"; // 8 bytes (size of a pointer of my 64-bit pc)

  // another way of converting to function pointer
  // unary + acts as a no-op, therefore the only legal result here is a function
  // pointer
  auto e = +[](int x, int ratio) { return x * ratio; };

  // preserving const
  int const f = 10;
  auto foo = [f]() mutable {
    std::cout << std::is_const<decltype(f)>::value << "\n";
  };
  foo();

  // iife
  int xx = 10, yy = 11;
  auto const zz = [xx, yy]() mutable noexcept {
    ++xx;
    --yy;

    return xx + yy;
  }();
  std::cout << "zz = " << zz << "\n";
}