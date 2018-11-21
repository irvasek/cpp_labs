#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "tasks.hpp"
#include "Shapes.hpp"

void lab8::doSecondTask(std::istream& in, std::ostream& out)
{
  std::vector<shape_ptr> shapes{std::istream_iterator<shape_ptr>(in),std::istream_iterator<shape_ptr>()};
  out << "Original:" << std::endl;
  std::copy(shapes.begin(),shapes.end(),std::ostream_iterator<shape_ptr>(out));
  out << "Left-Right:" << std::endl;
  std::sort(shapes.begin(),shapes.end(),
    [](const shape_ptr& shape1, const shape_ptr & shape2){return (*shape1).isMoreLeft(*shape2);});
  std::copy(shapes.begin(),shapes.end(),std::ostream_iterator<shape_ptr>(out));
  out << "Right-Left:" << std::endl;
  std::sort(shapes.begin(),shapes.end(),
    [](const shape_ptr& shape1, const shape_ptr & shape2){return !(*shape1).isMoreLeft(*shape2);});
  std::copy(shapes.begin(),shapes.end(),std::ostream_iterator<shape_ptr>(out));
  out << "Top-Bottom:" <<std::endl;
  std::sort(shapes.begin(),shapes.end(),
    [](const shape_ptr& shape1, const shape_ptr& shape2){return (*shape1).isUpper(*shape2);});
  std::copy(shapes.begin(),shapes.end(),std::ostream_iterator<shape_ptr>(out));
  out << "Bottom-Top:" << std::endl;
  std::sort(shapes.begin(),shapes.end(),
    [](const shape_ptr& shape1, const shape_ptr& shape2){return !(*shape1).isUpper(*shape2);});
  std::copy(shapes.begin(),shapes.end(),std::ostream_iterator<shape_ptr>(out));
}
