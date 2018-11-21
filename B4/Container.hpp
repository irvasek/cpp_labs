#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <iterator>

class Container
{
public:
  class Iterator: public std::iterator<std::bidirectional_iterator_tag, size_t>
  {
  public:
    Iterator():
      n_(1),
      result_(1)
    {}
    size_t& operator*();
    size_t* operator->();
    Iterator& operator++();
    Iterator operator++(int);
    Iterator& operator--();
    Iterator operator--(int);
    bool operator==(const Iterator & rhs) const;
    bool operator!=(const Iterator & rhs) const;
  private:
    size_t n_;
    size_t result_;
  };
  Iterator begin();
  Iterator end();
};

#endif // CONTAINER_HPP
