#include <iostream>
#include "tasks.hpp"

int main(int argc, char **argv)
{
  try
  {
    if(argc<2)
    {
      throw std::invalid_argument("Task number isn't stated");
    }
    switch(atoi(argv[1]))
    {
    case 1:
      if(argc<3)
      {
        throw std::invalid_argument("Order of sorting isn't stated");
      }
      else
      {
        lab_1::doFirstTask(argv[2]);
      }
      break;
    case 2:
      if(argc<3)
      {
        throw std::invalid_argument("File name isn't stated");
      }
      else
      {
        lab_1::doSecondTask(argv[2]);
      }
      break;
    case 3:
      lab_1::doThirdTask();
      break;
    case 4:
      if(argc<4)
      {
        throw std::invalid_argument("Order of sorting and/or vector size aren't stated");
      }
      else
      {
        lab_1::doFourthTask(argv[2],argv[3]);
      }
      break;
    default:
      throw std::invalid_argument("Invalid task number");
    }
  }
  catch(const std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
