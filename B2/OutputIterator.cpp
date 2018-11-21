#include "OutputIterator.hpp"

OutputIterator::~OutputIterator()
{
  if (value_.unique()&& !value_->line_.empty())
  {
    (*(value_->out_)) << value_->line_ << "\n";
  }
}
OutputIterator& OutputIterator::operator++()
{
  return *this;
}
OutputIterator OutputIterator::operator++(int)
{
  return *this;
}
OutputIterator& OutputIterator::operator*()
{
  return *this;
}
OutputIterator& OutputIterator::operator=(const token_t& token)
{
  if (!token.value_.empty())
  {
    switch (token.type_)
    {
      case token_t::word:
      case token_t::number:
        if (value_->line_.empty())
        {
          value_->line_ += token.value_;
          value_->pos_=0;
          break;
        }
        if ((value_->line_.size() + 1 + token.value_.size()) <= value_->width_)
        {
          value_->pos_=value_->line_.size();
          value_->line_ += (" " + token.value_);
        }
        else
        {
          (*(value_->out_)) << value_->line_ + "\n";
          value_->line_ = token.value_;
          value_->pos_=0;
        }
        break;
      case token_t::mark:
        if (value_->line_.size()+1 <= value_->width_)
        {
          value_->line_ += token.value_;
        }
        else
        {
          std::string tmp = value_->line_.substr(value_->pos_+1);
          value_->line_.erase(value_->pos_);
          (*(value_->out_)) << value_->line_ + "\n";
          value_->line_ = tmp + token.value_;
        }
        break;
      case token_t::dash:
        if ((value_->line_.size() + 4) <= value_->width_)
        {
          value_->line_ += (' ' + token.value_);
        }
        else
        {
          std::string tmp = value_->line_.substr(value_->pos_+1);
          value_->line_.erase(value_->pos_);
          (*(value_->out_)) << value_->line_ + "\n";
          value_->line_= tmp + ' ' + token.value_;
        }
        break;
      case token_t::space:
        break;
    }
  }
  return *this;
}
