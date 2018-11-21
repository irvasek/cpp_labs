#include <algorithm>
#include <iterator>
#include <cmath>
#include "tasks.hpp"

void lab8::doFirstTask(std::istream& in, std::ostream& out)
{
  std::transform(std::istream_iterator<double>(in),std::istream_iterator<double>(),
    std::ostream_iterator<double>(out," "),[](double value) { return value*M_PI; });
  if(!in.eof())
  {
    throw std::invalid_argument("Reading error");
  }
}
