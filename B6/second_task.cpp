#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator>
#include <cmath>
#include <limits>
#include <algorithm>
#include <numeric>
#include "tasks.hpp"

struct Point
{
  int x,y;
};
using Shape = std::vector<Point>;

std::ostream& operator<<(std::ostream& out, const Point& point)
{
  out << "(" << point.x << ";" << point.y << ")";
  return out;
}
std::ostream& operator<<(std::ostream& out, const Shape& shape)
{
  out << shape.size() << " ";
  std::copy(shape.begin(), shape.end(), std::ostream_iterator<Point>(out, " "));
  return out;
}
std::istream& operator>>(std::istream& in, Point& point)
{
  in.ignore(std::numeric_limits<std::streamsize>::max(), '(');
  in >> point.x;
  in.ignore(std::numeric_limits<std::streamsize>::max(), ';');
  in >> point.y;
  in.ignore(std::numeric_limits<std::streamsize>::max(), ')');
  return in;
}
std::istream& operator>>(std::istream& in, Shape& shape)
{
  if(in.eof())
  {
    in.setstate(std::ios::failbit);
    return in;
  }
  shape.clear();
  std::string line="";
  std::stringstream str_in;
  size_t n=0;
  while(n==0 && !in.eof())
  {
    std::getline(in,line);
    str_in.clear();
    str_in << line;
    str_in >> n;
  }
  if(!line.empty())
  {
    std::copy_n(std::istream_iterator<Point>(str_in), n, std::back_inserter(shape));
    if(str_in.fail())
    {
      throw std::ios_base::failure("Invalid data");
    }
    str_in >> std::ws;
    if(!str_in.eof())
    {
      throw std::invalid_argument("Invalid data");
    }
  }
  return in;
}

int getDist(const Point& p1, const Point& p2)
{
  return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

bool isRightAngle(const Point p1, const Point p2, Point p3)
{
  return getDist(p1,p2)+getDist(p2,p3)==getDist(p3,p1);
}

bool isRectangle(const Shape& shape)
{
  return (shape.size()==4)
    && isRightAngle(shape[0],shape[1],shape[2])
      && isRightAngle(shape[1],shape[2],shape[3])
        && isRightAngle(shape[2],shape[3],shape[0]);
}

bool isSquare(const Shape& shape)
{
  return isRectangle(shape)
    && (std::abs(shape.at(1).x - shape.at(0).x) == std::abs(shape.at(2).y - shape.at(1).y))
      && (std::abs(shape.at(2).x - shape.at(1).x) == std::abs(shape.at(1).y - shape.at(0).y));
}

bool isTriangle(const Shape& shape)
{
  return shape.size()==3;
}

void lab6::doSecondTask()
{
  std::vector<Shape> shapes={};
  std::copy(std::istream_iterator<Shape>(std::cin), std::istream_iterator<Shape>()
    ,std::insert_iterator<std::vector<Shape>>(shapes, shapes.begin()));
  int vertices = std::accumulate(shapes.begin(), shapes.end(), 0,
    [](int sum, const Shape& shape) { return sum+shape.size(); });
  std::cout << "Vertices: " << vertices << std::endl;
  int triangles = std::count_if(shapes.begin(),shapes.end(),isTriangle);
  std::cout << "Triangles: " << triangles << std::endl;
  int squares = std::count_if(shapes.begin(),shapes.end(),isSquare);
  std::cout << "Squares: " << squares << std::endl;
  int rectangles = std::count_if(shapes.begin(),shapes.end(),isRectangle);
  std::cout << "Rectangles: " << rectangles << std::endl;
  shapes.erase(std::remove_if(shapes.begin(),shapes.end(),
    [](const Shape & shape) { return shape.size() == 5; }),shapes.end());
  std::vector<Point> points={};
  std::transform(shapes.begin(),shapes.end(),
    std::back_inserter(points),[](const Shape& shape) { return shape.front(); });
  std::cout << "Points: ";
  std::copy(points.begin(), points.end(), std::ostream_iterator<Point>(std::cout, " "));
  std::cout << std::endl << "Shapes:" << std::endl;
  auto triangle_end = std::partition(shapes.begin(), shapes.end(), isTriangle);
  auto square_end = std::partition(triangle_end, shapes.end(), isSquare);
  std::partition(square_end, shapes.end(), isRectangle);
  std::copy(shapes.begin(), shapes.end(), std::ostream_iterator<Shape>(std::cout, "\n"));
}
