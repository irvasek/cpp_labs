#include <iostream>
#include <string>
#include <set>
#include "tasks.hpp"

void lab6::doFirstTask()
{
  std::set<std::string> words={};
  std::string word="";
  while(std::cin >> word)
  {
    if(words.count(word)==0)
    {
      words.insert(word);
      std::cout << word << std::endl;
    }
  }
  if(!std::cin.eof())
  {
    throw std::ios_base::failure("Reading error");
  }
}
