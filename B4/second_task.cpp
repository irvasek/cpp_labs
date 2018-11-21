#include <iostream>
#include <algorithm>
#include "tasks.hpp"
#include "Container.hpp"

void lab4::doSecondTask()
{
  Container fact_container={};
  std::copy(fact_container.begin(), fact_container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
  std::reverse_copy(fact_container.begin(), fact_container.end(), std::ostream_iterator<int>(std::cout, " "));
  std::cout << std::endl;
}
