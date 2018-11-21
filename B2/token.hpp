#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>

struct token_t
{
  enum token_type
  {
    space,
    word,
    number,
    dash,
    mark
  };
  token_type type_;
  std::string value_;
};

#endif //TOKEN_HPP
