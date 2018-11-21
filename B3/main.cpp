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
    switch(std::atoi(argv[1]))
    {
    case 1:
      lab3::doFirstTask();
      break;
    case 2:
      lab3::doSecondTask();
      break;
    default:
      throw std::invalid_argument("Invalid task number");
      break;
    }
  }
  catch(std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
