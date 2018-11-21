#ifndef STATISTIC_HPP
#define STATISTIC_HPP

#include <algorithm>
#include <iostream>

class Statistic
{
public:
  Statistic():
    min_(std::numeric_limits<int>::max()),
    max_(std::numeric_limits<int>::min()),
    count_(0),
    pos_count_(0),
    neg_count_(0),
    odd_sum_(0),
    even_sum_(0)
  {}
  void operator()(int value);
  void print(std::ostream& out);
private:
  int min_;
  int max_;
  int count_;
  int pos_count_;
  int neg_count_;
  long long int odd_sum_;
  long long int even_sum_;
  int first_;
  int last_;
};

#endif // STATISTIC_HPP
