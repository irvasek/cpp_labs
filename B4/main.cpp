#include <iostream>
#include "tasks.hpp"

int main(int argc, char** argv)
{
  try
  {
    if (argc != 2)
    {
      std::cerr << "Invalid number of arguments" << std::endl;
      return 1;
    }
    switch (std::stoi(argv[1]))
    {
    case 1:
      lab4::doFirstTask();
      break;
    case 2:
      lab4::doSecondTask();
      break;
    default:
      std::cerr << "Invalid task number" << std::endl;
      return 1;
    }
  }
  catch (std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 2;
  }
  return 0;
}
