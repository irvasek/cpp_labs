#include <vector>
#include "tasks.hpp"
#include "impl.hpp"

void lab_1::doThirdTask()
{
  std::vector<int> vector={};
  int value=0;
  while (std::cin && !(std::cin >> value).eof())
  {
    if (std::cin.fail())
    {
      throw std::ios_base::failure("Error reading");
    }
    if (value == 0)
    {
      break;
    }
    vector.push_back(value);
  }
  if(value!=0)
  {
    throw std::invalid_argument("End of input must be zero");
  }
  if(!vector.empty())
  {
    switch (vector.back())
    {
    case 1:
      for(auto i = vector.begin(); i < vector.end();)
      {
        if (!(*i & 1))
        {
          i = vector.erase(i);
        }
        else
        {
          i++;
        }
      }
      break;
    case 2:
      for (auto i = vector.begin(); i < vector.end();)
      {
        if (*i % 3 == 0)
        {
          i=vector.insert(i + 1, { 1, 1, 1 });
          i += 3;
        }
        else
        {
          i++;
        }
      }
      break;
    }
    print(vector);
  }
}
