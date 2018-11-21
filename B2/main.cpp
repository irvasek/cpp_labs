#include <iostream>
#include "InputIterator.hpp"
#include "OutputIterator.hpp"

int main(int args, char** argv)
{
  size_t width=40;
  const size_t min_line_width=24;
  try
  {
    if(args > 1)
    {
      if(args != 3)
      {
        throw std::invalid_argument("Invalid number of parameters");
      }
      if(std::string(argv[1]) != "--line-width")
      {
        throw std::invalid_argument("Invalid argument");
      }
      width=std::atoi(argv[2]);
      if(width<=min_line_width)
      {
        throw std::invalid_argument("Invalid line width");
      }
    }
    std::copy(InputIterator(std::cin), InputIterator(), OutputIterator(std::cout, width));
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
