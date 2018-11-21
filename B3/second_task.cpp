#include <iostream>
#include <list>
#include "tasks.hpp"

#define MIN_VALUE 1
#define MAX_VALUE 20
#define SIZE 20

void lab3::doSecondTask()
{
  std::list<int> list{};
  int value=0;
  while(std::cin >> value)
  {
    if(value >= MIN_VALUE && value <= MAX_VALUE)
    {
      list.push_back(value);
    }
    else
    {
      throw std::invalid_argument("Invalid input data: numbers between " + std::to_string(MIN_VALUE)
        +" and "+std::to_string(MAX_VALUE));
    }
  }
  if(!std::cin.eof())
  {
    throw std::ios_base::failure("Reading error");
  }
  if(list.size()>SIZE)
  {
    throw std::invalid_argument("Invalid input data: only "+std::to_string(SIZE)+" numbers");
  }
  std::list<int>::iterator begin = list.begin();
  std::list<int>::iterator end = list.end();
  end--;
  while(begin!=end)
  {
    std::cout << *begin << " " << *end << " ";
    begin++;
    if(begin==end)
    {
      break;
    }
    end--;
  }
  if(list.size()&1)
  {
    std::cout << *begin;
  }
  std::cout << std::endl;
}
