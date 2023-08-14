#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

void
CallablePrint(std::string const& name)
{
  std::cout << "Hello " << name << ", what's up?"
            << "\n";
}

struct AnotherCallablePrint
{
  void operator()(std::string const& name)
  {
    std::cout << "Eyy " << name << ", does it work?"
              << "\n";
  }
};

int
main()
{
  std::vector<std::string> developers;
  developers.push_back("Void");
  developers.push_back("Lina");
  developers.push_back("EarthShaker");
  developers.push_back("TemplarAssasin");
  developers.push_back("GrimStroke");

  std::for_each(developers.begin(), developers.end(), CallablePrint);

  std::cout << "\n\n";

  AnotherCallablePrint anotherCallableObj;
  std::for_each(developers.begin(), developers.end(), anotherCallableObj);

  std::vector<int> goodNumbers;
  goodNumbers.push_back(1);
  goodNumbers.push_back(2);
  goodNumbers.push_back(3);
  goodNumbers.push_back(4);
  goodNumbers.push_back(5);

  int x = std::count_if(
    goodNumbers.begin(), goodNumbers.end(), std::bind2nd(std::less<int>(), 2)
  );

  std::cout << "x = " << x << "\n";
}