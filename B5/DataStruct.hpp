#ifndef DATA_STRUCT_HPP
#define DATA_STRUCT_HPP

#include <string>
#include <iostream>
#include <sstream>

#define MIN -5
#define MAX 5

struct DataStruct
{
  int key1;
  int key2;
  std::string str;
  bool operator<(const DataStruct& data);
};

int readKey(std::istringstream& line);
std::istream& operator>>(std::istream& in, DataStruct& data);
std::ostream& operator<<(std::ostream& out, const DataStruct& data) noexcept;

#endif // DATA_STRUCT_HPP
