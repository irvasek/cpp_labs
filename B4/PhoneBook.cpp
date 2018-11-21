#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
  marks_["current"]=phone_book_.end();
}
void PhoneBook::pushBack(const recordType& record) noexcept
{
  phone_book_.push_back(record);
  if(phone_book_.size()==1)
  {
    marks_["current"]=phone_book_.begin();
  }
}
void PhoneBook::insertMark(std::string mark_name,std::string new_mark_name)
{
  marksIter iterator=getIterator(mark_name);
  marks_[new_mark_name]=iterator->second;
}
void PhoneBook::insert(bool is_before, std::string mark_name, const PhoneBook::recordType& record)
{
  if(phone_book_.empty())
  {
    pushBack(record);
  }
  else
  {
    marksIter iterator=getIterator(mark_name);
    if(is_before)
    {
      phone_book_.insert(iterator->second,record);
    }
    else
    {
      phone_book_.insert(std::next(iterator->second),record);
    }
  }
}
void PhoneBook::del(std::string mark_name)
{
  phoneBookIter iter=getIterator(mark_name)->second;
  for (marksIter i=marks_.begin();i!=marks_.end();i++)
  {
    if (i->second == iter)
    {
      i->second++;
      if (i->second == phone_book_.end() && phone_book_.size() > 1)
      {
        std::advance(i->second, -2);
      }
    }
  }
  phone_book_.erase(iter);
}
void PhoneBook::show(std::string mark_name)
{
  marksIter iterator=getIterator(mark_name);
  if(phone_book_.empty())
  {
    throw std::invalid_argument("<EMPTY>");
  }
  std::cout << iterator->second->first << " " << iterator->second->second << std::endl;
}
void PhoneBook::jumpToNext(std::string mark_name)
{
  jumpOver(mark_name,1);
}
void PhoneBook::jumpToPrevious(std::string mark_name)
{
  jumpOver(mark_name,-1);
}
void PhoneBook::jumpOver(std::string mark_name,int step)
{
  marksIter iterator = getIterator(mark_name);
  std::advance(iterator->second,step);
}
void PhoneBook::jumpOver(std::string mark_name,std::string step)
{
  marksIter iterator=getIterator(mark_name);
  if(!phone_book_.empty())
  {
    if(step=="first")
    {
      iterator->second=phone_book_.begin();
    }
    else
    {
      iterator->second=std::prev(phone_book_.end());
    }
  }
}
void PhoneBook::replace(std::string mark_name,recordType& record)
{
  marksIter iterator=getIterator(mark_name);
  *(iterator->second)=record;
}
PhoneBook::marksIter PhoneBook::getIterator(std::string mark_name)
{
  marksIter iterator = marks_.find(mark_name);
  if (iterator==marks_.end())
  {
    throw std::invalid_argument("<INVALID BOOKMARK>");
  }
  return iterator;
}
