#include <algorithm>
#include "UserInterface.hpp"

std::string readNumber(std::istream& in)
{
  std::string number="";
  in >> number;
  for(char symbol:number)
  {
    if(!std::isdigit(symbol))
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return number;
}
std::string readName(std::istream& in)
{
  in.ignore();
  std::string name="";
  std::getline(in,name);
  if(name.front()!='\"' || name.back()!='\"')
  {
    throw std::invalid_argument("<INVALID COMMAND>");
  }
  name.erase(0,1);
  name.pop_back();
  name.erase(std::remove(name.begin(),name.end(),'\\'),name.end());
  return name;
}

std::string readMarkName(std::istream& in)
{
  std::string mark_name="";
  in >> mark_name;
  for(char symbol:mark_name)
  {
    if(!std::isalnum(symbol) && symbol!='-')
    {
      throw std::invalid_argument("<INVALID COMMAND>");
    }
  }
  return mark_name;
}

void add(PhoneBook& phone_book, std::istream& in)
{
  std::string number=readNumber(in);
  std::string name=readName(in);
  phone_book.pushBack(PhoneBook::recordType{number,name});
}
void store(PhoneBook& phone_book, std::istream& in)
{
  std::string mark_name=readMarkName(in);
  std::string new_mark_name=readMarkName(in);
  phone_book.insertMark(mark_name,new_mark_name);
}
void insertBefore(PhoneBook& phone_book, std::istream& in)
{
  std::string mark_name=readMarkName(in);
  std::string number=readNumber(in);
  std::string name=readName(in);
  phone_book.insert(true, mark_name, PhoneBook::recordType{number, name});
}
void insertAfter(PhoneBook& phone_book, std::istream& in)
{
  std::string mark_name=readMarkName(in);
  std::string number=readNumber(in);
  std::string name=readName(in);
  phone_book.insert(false, mark_name, PhoneBook::recordType{number, name});
}
void del(PhoneBook& phone_book, std::istream& in)
{
  std::string mark_name=readMarkName(in);
  phone_book.del(mark_name);
}
void show(PhoneBook& phone_book, std::istream& in)
{
  std::string mark_name=readMarkName(in);
  phone_book.show(mark_name);
}
void move(PhoneBook& phone_book, std::istream& in)
{
  std::string mark_name=readMarkName(in);
  std::string step="";
  in.ignore();
  std::getline(in, step);
  if (step=="first" || step=="last")
  {
    phone_book.jumpOver(mark_name, step);
  }
  else
  {
    try
    {
      phone_book.jumpOver(mark_name,stoi(step));
    }
    catch(std::invalid_argument& e)
    {
      std::cout << "<INVALID STEP>" << std::endl;
    }
  }
}
