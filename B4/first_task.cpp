#include <iostream>
#include <string>
#include <sstream>
#include "tasks.hpp"
#include "UserInterface.hpp"

void lab4::doFirstTask()
{
  PhoneBook phone_book={};
  std::string line="";
  while(std::getline(std::cin,line))
  {
    try
    {
      std::stringstream in(line);
      std::string value="";
      in >> value;
      if (value=="add")
      {
        add(phone_book,in);
      }
      else if (value == "insert")
      {
        std::string pos="";
        in >> pos;
        if(pos=="before")
        {
          insertBefore(phone_book,in);
        }
        else if(pos=="after")
        {
          insertAfter(phone_book,in);
        }
        else
        {
          throw std::invalid_argument("<INVALID COMMAND>");
        }
      }
      else if (value == "delete")
      {
        del(phone_book,in);
      }
      else if (value == "store")
      {
        store(phone_book,in);
      }
      else if (value == "move")
      {
        move(phone_book,in);
      }
      else if (value == "show")
      {
        show(phone_book,in);
      }
      else
      {
        throw std::invalid_argument("<INVALID COMMAND>");
      }
    }
    catch (std::invalid_argument& e)
    {
      std::cout << e.what() << std::endl;
    }
  }
}
