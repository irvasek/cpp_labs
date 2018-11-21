#include "Shapes.hpp"
#include <limits>
#include <sstream>
#include <string>

bool Shape::isMoreLeft(const Shape& shape) const noexcept
{
  return point_.x<shape.point_.x;
}
bool Shape::isUpper(const Shape& shape) const noexcept
{
  return point_.y>shape.point_.y;
}

void Circle::draw(std::ostream& out) const noexcept
{
  out << "CIRCLE " << point_<< std::endl;
}

void Square::draw(std::ostream& out) const noexcept
{
  out << "SQUARE " << point_ << std::endl;
}

void Triangle::draw(std::ostream& out) const noexcept
{
  out << "TRIANGLE " << point_ << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Point& point) noexcept
{
  out << "(" << point.x << ";" << point.y << ")";
  return out;
}
std::istream& operator>>(std::istream& in, Point& point) noexcept
{
  in >> point.x;
  in.ignore(std::numeric_limits<std::streamsize>::max(), ';');
  in >> point.y;
  in.ignore(std::numeric_limits<std::streamsize>::max(), ')');
  return in;
}

std::istream& operator>>(std::istream& in, shape_ptr& shape_ptr)
{
  if(in.eof())
  {
    in.setstate(std::istream::failbit);
    return in;
  }
  std::string line="";
  std::getline(in >> std::ws,line);
  if(!line.empty())
  {
    std::stringstream in_str(line);
    std::string shape_type="";
    std::getline(in_str,shape_type,'(');
    Point point={};
    in_str >> point;
    if(in_str.fail())
    {
      throw std::ios_base::failure("Invalid data");
    }
    if(shape_type.find("CIRCLE")!=std::string::npos)
    {
      shape_ptr = std::make_shared<Circle>(Circle(point));
    }
    else if(shape_type.find("SQUARE")!=std::string::npos)
    {
      shape_ptr = std::make_shared<Square>(Square(point));
    }
    else if(shape_type.find("TRIANGLE")!=std::string::npos)
    {
      shape_ptr = std::make_shared<Triangle>(Triangle(point));
    }
    else
    {
      throw std::invalid_argument("Invalid data");
    }
  }
  return in;
}
std::ostream& operator<<(std::ostream& out, const shape_ptr& shape_ptr) noexcept
{
  (*shape_ptr).draw(out);
  return out;
}
