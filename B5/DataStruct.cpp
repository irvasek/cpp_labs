#include "DataStruct.hpp"

bool DataStruct::operator<(const DataStruct& data)
{
  if(key1==data.key1)
  {
    if(key2==data.key2)
    {
      return (str.size()<data.str.size());
    }
    return (key2<data.key2);
  }
  return (key1<data.key1);
}

int readKey(std::istringstream& line)
{
  int key=0;
  line >> key;
  if(key<MIN || key>MAX)
  {
    throw std::invalid_argument("Key should be between "+std::to_string(MIN)+" and "+std::to_string(MAX));
  }
  char symbol='\0';
  line >> symbol;
  if (symbol!=',' || !line)
  {
    throw std::invalid_argument("Invalid delimiter");
  }
  return key;
}

std::istream& operator>>(std::istream& in,DataStruct& data)
{
  std::string str="";
  std::getline(in,str);
  if(!str.empty())
  {
    std::istringstream line(str);
    int key1=readKey(line);
    int key2=readKey(line);
    std::getline(line,str);
    if (str.empty() || !line)
    {
      throw std::invalid_argument("Empty string");
    }
    data.key1=key1;
    data.key2=key2;
    data.str=str;
  }
  return in;
}

std::ostream& operator<<(std::ostream& out,const DataStruct& data) noexcept
{
  out << data.key1 << "," << data.key2 << "," << data.str;
  return out;
}
