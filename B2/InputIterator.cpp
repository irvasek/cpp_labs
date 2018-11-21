#include "InputIterator.hpp"
#include <iostream>

#define MAX_WORD_LENGTH 20
#define DASH_LENGTH 3

bool InputIterator::operator==(const InputIterator& iterator) const
{
  return value_==iterator.value_;
}
bool InputIterator::operator!=(const InputIterator& iterator) const
{
  return !(*this==iterator);
}
const token_t& InputIterator::operator*() const
{
  return value_->current_;
}
const token_t* InputIterator::operator->() const
{
  return &(value_->current_);
}
InputIterator& InputIterator::operator++()
{
  if(!(*(value_->in_)))
  {
    value_=nullptr;
  }
  else
  {
    readToken();
  }
  return *this;
}
InputIterator InputIterator::operator++(int)
{
  InputIterator tmp(*this);
  ++(*this);
  return tmp;
}
void InputIterator::readNumber(char& symbol)
{
  token_t number{token_t::number,""};
  size_t length=0;
  bool isPoint=false;
  char point = std::use_facet<std::numpunct<char>>(std::locale()).decimal_point();
  do
  {
    if(symbol==point)
    {
      isPoint=true;
    }
    number.value_.push_back(symbol);
    length++;
    if(length>MAX_WORD_LENGTH)
    {
      throw std::invalid_argument("Invalid number: number's length must be less then 21");
    }
    symbol=readSymbol();
  }while(std::isdigit(symbol, std::locale()) || (symbol==point && !isPoint));
  if((length==1 && !std::isdigit(number.value_.back(), std::locale()))
    || number.value_.back()==point)
  {
    throw std::invalid_argument("Invalid number");
  }
  value_->current_=number;
}
void InputIterator::readDash(char& symbol)
{
  size_t length=0;
  token_t dash{token_t::dash,""};
  do
  {
    dash.value_.push_back(symbol);
    length++;
    symbol=readSymbol();
  }while(length<DASH_LENGTH && symbol=='-');
  if(length<DASH_LENGTH)
  {
    throw std::invalid_argument("Invalid symbol");
  }
  value_->current_=dash;
}
void InputIterator::readWord(char& symbol)
{
  token_t word{token_t::word,""};
  size_t length=0;
  do
  {
    if(symbol=='-' && value_->in_->peek()=='-')
    {
      break;
    }
    word.value_.push_back(symbol);
    length++;
    if(length>MAX_WORD_LENGTH)
    {
      throw std::invalid_argument("Invalid word: word's length must be less then 21");
    }
    symbol=readSymbol();
  }while(std::isalpha(symbol, std::locale())||symbol=='-');
  value_->current_=word;
}
char InputIterator::readSymbol()
{
  char symbol='\0';
  if(*(value_->in_))
  {
    symbol=value_->in_->get();
  }
  else
  {
    throw std::ios_base::failure("Reading error");
  }
  return symbol;
}
void InputIterator::readToken()
{
  char symbol=readSymbol();
  while(std::isspace(symbol,std::locale()))
  {
    symbol=readSymbol();
  }
  if(std::isalpha(symbol, std::locale()))
  {
    readWord(symbol);
  }
  else if(std::isdigit(symbol, std::locale()) || symbol=='+')
  {
    readNumber(symbol);
  }
  else if(symbol=='-')
  {
    if(std::isdigit<char>(value_->in_->peek(), std::locale()))
    {
      readNumber(symbol);
    }
    else
    {
      bool check=(value_->current_.type_==token_t::space || ((value_->current_.type_==token_t::mark)
        && !(value_->current_.value_==",")) || value_->current_.type_==token_t::dash);
      readDash(symbol);
      if(check)
      {
        throw std::invalid_argument("Invalid symbol: punctuation marks cannot follow each other or be first");
      }
    }
  }
  else if(std::ispunct(symbol, std::locale()))
  {
    if(value_->current_.type_==token_t::space|| value_->current_.type_==token_t::mark
      || value_->current_.type_==token_t::dash)
    {
      throw std::invalid_argument("Invalid symbol: punctuation marks cannot follow each other or be first");
    }
    token_t mark{token_t::mark,""};
    mark.value_.push_back(symbol);
    value_->current_=mark;
    symbol=readSymbol();
  }
  else
  {
    value_->current_={token_t::space,""};
  }
  value_->in_->unget();
}
