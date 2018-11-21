#include <iostream>
#include <vector>
#include <forward_list>
#include "tasks.hpp"
#include "impl.hpp"

void lab_1::doFirstTask(const char* order)
{
  bool is_ascending=checkOrder(order);
  std::vector<int> vector={};
  int value=0;
  while ((std::cin) && !(std::cin >> value).eof())
  {
    if (std::cin.fail() || std::cin.bad())
    {
      throw std::ios_base::failure("Error reading");
    }
    vector.push_back(value);
  }

  if(!vector.empty())
  {
    std::vector<int> vector_1(vector.begin(),vector.end());
    std::forward_list<int> forward_list(vector.begin(),vector.end());
    sort<BracketsAccess>(vector_1, is_ascending);
    print(vector_1);
    sort<AtAccess>(vector_1,is_ascending);
    print(vector_1);
    sort<IteratorAccess>(forward_list, is_ascending);
    print(forward_list);
  }
}
