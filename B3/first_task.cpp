#include <iostream>
#include <string>
#include "tasks.hpp"
#include "QueueWithPriority.hpp"

void lab3::doFirstTask()
{
  QueueWithPriority<std::string> queue{};
  std::string value="";
  while(std::cin >> value)
  {
    if(value=="add")
    {
      std::string priority="";
      std::cin >> priority;
      std::cin.ignore();
      std::string data="";
      std::getline(std::cin,data);
      if(data.empty())
      {
        std::cout << "<INVALID COMMAND>" << std::endl;
      }
      if(priority=="high")
      {
        queue.putElementToQueue(data,ElementPriority::HIGH);
      } else if(priority=="normal")
      {
        queue.putElementToQueue(data,ElementPriority::NORMAL);
      } else if(priority=="low")
      {
        queue.putElementToQueue(data,ElementPriority::LOW);
      } else
      {
        std::cout << "<INVALID COMMAND>" << std::endl;
      }

    } else if(value=="get")
    {
      try
      {
        std::cout << queue.getElementFromQueue() << std::endl;
      }
      catch(std::out_of_range& e)
      {
        std::cout << "<EMPTY>" << std::endl;
      }
    } else if(value=="accelerate")
    {
      queue.accelerate();
    }
    else
    {
      std::cout << "<INVALID COMMAND>" << std::endl;
    }
  }
  if (!std::cin.eof())
  {
    throw std::ios_base::failure("Reading error");
  }

}
