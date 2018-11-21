#ifndef PHONE_BOOK_HPP
#define PHONE_BOOK_HPP

#include <list>
#include <map>
#include <string>

class PhoneBook
{
public:
  using recordType=std::pair<std::string,std::string>;
  using phoneBookIter=std::list<recordType>::iterator;
  using marksIter=std::map<std::string,phoneBookIter>::iterator;
  PhoneBook();
  void pushBack(const recordType& record) noexcept;
  void insertMark(std::string mark_name,std::string new_mark_name);
  void insert(bool is_before, std::string mark_name, const recordType& record);
  void del(std::string mark_name);
  void show(std::string mark_name);
  void jumpOver(std::string mark_name,int step);
  void jumpOver(std::string mark_name,std::string step);
  void jumpToNext(std::string mark_name);
  void jumpToPrevious(std::string mark_name);
  void replace(std::string mark_name,recordType& record);
private:
  std::list<recordType> phone_book_;
  std::map<std::string,std::list<recordType>::iterator> marks_;
  marksIter getIterator(std::string mark_name);
};

#endif // PHONE_BOOK_HPP
