#include "Container.hpp"

size_t& Container::Iterator::operator*()
{
  return result_;
}
size_t* Container::Iterator::operator->()
{
  return &result_;
}
Container::Iterator& Container::Iterator::operator++()
{
  result_*=++n_;
  return *this;
}
Container::Iterator Container::Iterator::operator++(int)
{
  Iterator tmp=*this;
  ++(*this);
  return tmp;
}
Container::Iterator& Container::Iterator::operator--()
{
  result_/=n_--;
  return *this;
}
Container::Iterator Container::Iterator::operator--(int)
{
  Iterator tmp=*this;
  --(*this);
  return tmp;
}
bool Container::Iterator::operator==(const Iterator & rhs) const
{
  return n_==rhs.n_;
}
bool Container::Iterator::operator!=(const Iterator & rhs) const
{
  return !(*this==rhs);
}
Container::Iterator Container::begin()
{
  return Iterator();
}
Container::Iterator Container::end()
{
  Iterator iterator{};
  std::advance(iterator, 10);
  return iterator;

}
