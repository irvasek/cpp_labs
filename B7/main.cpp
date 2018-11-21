#include <iostream>
#include <iterator>
#include <functional>
#include "Statistic.hpp"

int main()
{
  Statistic stat={};
  std::for_each(std::istream_iterator<long long int>(std::cin), std::istream_iterator<long long int>(), std::ref(stat));
  if(!std::cin.eof())
  {
    std::cerr << "Invalid input";
    return 1;
  }
  stat.print(std::cout);
  return 0;
}
