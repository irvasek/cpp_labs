#include <cstring>
#include "impl.hpp"

bool checkOrder(const char * order)
{
  bool is_ascending = true;
  if(strcmp(order,"descending")==0)
  {
    is_ascending=false;
  }
  else
  {
    if(!(strcmp(order,"ascending")==0))
    {
      throw std::invalid_argument("Invalid order value");
    }
  }
  return is_ascending;
}
