#include <iostream>
#include "tasks.hpp"

int main(int argc, char** argv)
{
  try
  {
    if(argc!=2)
    {
      throw std::invalid_argument("Invalid number of arguments");
    }
    switch(std::stoi(argv[1]))
    {
    case 1:
      lab8::doFirstTask(std::cin, std::cout);
      break;
    case 2:
      lab8::doSecondTask(std::cin, std::cout);
      break;
    default:
      throw std::invalid_argument("Invalid task number");
    }
  }
  catch(std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
