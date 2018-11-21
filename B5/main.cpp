#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "DataStruct.hpp"

int main()
{
  try
  {
    std::vector<DataStruct> vector={};
    std::copy(std::istream_iterator<DataStruct>(std::cin),std::istream_iterator<DataStruct>(),std::back_inserter(vector));
    std::sort(vector.begin(),vector.end());
    std::copy(vector.begin(),vector.end(),std::ostream_iterator<DataStruct>(std::cout,"\n"));
  }
  catch(std::exception& e)
  {
    std::cerr << e.what() << std::endl;
    return 1;
  }
  return 0;
}
