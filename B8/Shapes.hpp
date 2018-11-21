#ifndef SHAPES_HPP
#define SHAPES_HPP

#include <iostream>
#include <memory>

struct Point
{
  int x;
  int y;
};

class Shape
{
public:
  Shape(const Point& point):
    point_(point)
  {}
  virtual ~Shape() = default;
  bool isMoreLeft(const Shape& shape) const noexcept;
  bool isUpper(const Shape& shape) const noexcept;
  virtual void draw(std::ostream& out) const noexcept = 0;
protected:
  Point point_;
};

class Circle: public Shape
{
public:
  Circle(const Point& point):
    Shape(point)
  {}
  void draw(std::ostream& out) const noexcept override;
};

class Square: public Shape
{
public:
  Square(const Point& point):
    Shape(point)
  {}
  void draw(std::ostream& out) const noexcept override;
};

class Triangle: public Shape
{
public:
  Triangle(const Point& point):
    Shape(point)
  {}
  void draw(std::ostream& out) const noexcept override;
};

using shape_ptr=std::shared_ptr<Shape>;
std::istream& operator>>(std::istream& in, shape_ptr& shape_ptr);
std::ostream& operator<<(std::ostream& out, const shape_ptr& shape_ptr) noexcept;
std::istream& operator>>(std::istream& in, Point& point) noexcept;
std::ostream& operator<<(std::ostream& out, const Point& point) noexcept;

#endif // SHAPE_HPP
