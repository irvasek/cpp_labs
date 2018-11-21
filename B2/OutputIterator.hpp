#ifndef OUTPUT_ITERATOR_HPP
#define OUTPUT_ITERATOR_HPP

#include <iostream>
#include <memory>
#include "token.hpp"

class OutputIterator: public std::iterator<std::output_iterator_tag, token_t>
{
public:
  OutputIterator() :
    value_(nullptr)
  {}
  OutputIterator(std::ostream& out, size_t width):
    value_(std::make_shared<value_t>(out, width))
  {}
  ~OutputIterator();
  OutputIterator& operator=(const token_t& token);
  OutputIterator& operator*();
  OutputIterator& operator++();
  OutputIterator operator++(int);
private:
  struct value_t
  {
    std::ostream* out_;
    const size_t width_;
    std::string line_;
    size_t pos_;
    value_t(std::ostream& out, size_t width):
      out_(&out),
      width_(width),
      line_(),
      pos_()
    {}
  };
  std::shared_ptr<value_t> value_;
};

#endif // OUTPUT_ITERATOR_HPP
