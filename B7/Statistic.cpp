#include "Statistic.hpp"

void Statistic::operator()(int value)
{
  count_++;
  if(value<min_)
  {
    min_=value;

  }
  if(value>max_)
  {
    max_=value;
  }
  if(value>0)
  {
    pos_count_++;
  }
  else if(value<0)
  {
    neg_count_++;
  }
  if(value&1)
  {
    odd_sum_+=value;
  }
  else
  {
    even_sum_+=value;
  }
  if(count_==1)
  {
    first_=value;
  }
  last_=value;
}

void Statistic::print(std::ostream& out)
{
  if(count_==0)
  {
    out << "No Data" << std::endl;
    return;
  }
  out << "Max: " << max_ << std::endl;
  out << "Min: " << min_ << std::endl;
  out << "Mean: " << static_cast<double>(even_sum_+odd_sum_)/static_cast<double>(count_) << std::endl;;
  out << "Positive: " << pos_count_ << std::endl;
  out << "Negative: " << neg_count_ << std::endl;
  out << "Odd Sum: " << odd_sum_ << std::endl;
  out << "Even Sum: " << even_sum_ << std::endl;
  out << "First/Last Equal: " << (first_==last_?"yes":"no") << std::endl;
}
