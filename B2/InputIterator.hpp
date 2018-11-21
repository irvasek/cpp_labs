#ifndef INPUT_ITERATOR_HPP
#define INPUT_ITERATOR_HPP

#include <iostream>
#include <memory>
#include "token.hpp"

class InputIterator: public std::iterator<std::input_iterator_tag,token_t>
{
public:
  InputIterator():
    value_(nullptr)
  {}
  InputIterator(std::istream& in):
    value_(std::make_shared<value_t>(in))
  {}
  bool operator==(const InputIterator& iterator) const;
  bool operator!=(const InputIterator& iterator) const;
  const token_t& operator*() const;
  const token_t* operator->() const;
  InputIterator& operator++();
  InputIterator operator++(int);
private:
  struct value_t
  {
    std::istream* in_;
    token_t current_;
    value_t(std::istream& in):
      in_(&in),
      current_()
    {}
  };
  std::shared_ptr<value_t> value_;
  void readNumber(char& symbol);
  void readDash(char& symbol);
  void readWord(char& symbol);
  char readSymbol();
  void readToken();
};

#endif // INPUT_ITERATOR_HPP
