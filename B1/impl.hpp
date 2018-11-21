#ifndef IMPL_HPP
#define IMPL_HPP

#include <iostream>

template<typename Container>
class BracketsAccess
{
public:
  using value_type = typename Container::value_type;
  static value_type& getElement(Container &container, size_t index)
  {
    return container[index];
  }
  static size_t getBegin(const Container &)
  {
    return 0;
  }
  static size_t getEnd(const Container &container)
  {
    return container.size();
  }
};

template<typename Container>
class AtAccess
{
public:
  using value_type = typename Container::value_type;
  static value_type& getElement(Container &container, size_t index)
  {
    return container.at(index);
  }
  static size_t getBegin(const Container &)
  {
    return 0;
  }
  static size_t getEnd(const Container &container)
  {
    return container.size();
  }
};

template<typename Container>
class IteratorAccess
{
public:
  using iterator = typename Container::iterator;
  using value_type = typename Container::value_type;
  static value_type& getElement(Container &, iterator &index)
  {
    return *index;
  }
  static iterator getBegin(Container &container)
  {
    return container.begin();
  }
  static iterator getEnd(Container &container)
  {
    return container.end();
  }
};

bool checkOrder(const char * order);

template<template <typename Container> class AccessType, typename Container>
void sort(Container &container, bool is_ascending)
{
  for(auto i=AccessType<Container>::getBegin(container); i!=AccessType<Container>::getEnd(container);i++)
  {
    for(auto j=i; j!=AccessType<Container>::getEnd(container);j++)
    {
      if(is_ascending?AccessType<Container>::getElement(container,i)>AccessType<Container>::getElement(container,j)
        :AccessType<Container>::getElement(container,i)<AccessType<Container>::getElement(container,j))
      {
        std::swap(AccessType<Container>::getElement(container,i), AccessType<Container>::getElement(container,j));
      }
    }
  }
}

template<typename Container>
void print(const Container &container)
{
  for(auto value:container)
  {
    std::cout << value << ' ';
  }
  std::cout << std::endl;
}

#endif // IMPL_HPP
