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
      lab6::doFirstTask();
      break;
    case 2:
      lab6::doSecondTask();
      break;
    default:
      throw std::invalid_argument("Invalid argument number");
    }
  }
  catch(std::exception& e)
  {
    std::cout << e.what() << std::endl;
    return 1;
  }
  return 0;
}
