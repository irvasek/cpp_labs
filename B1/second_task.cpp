#include <fstream>
#include <vector>
#include <memory>
#include "tasks.hpp"
#include "impl.hpp"

void lab_1::doSecondTask(const char* file_name)
{
  std::ifstream stream(file_name);
  if(!stream)
  {
    throw std::ios_base::failure("Cannot open file");
  }
  stream.seekg(0 , std::ios_base::end);
  size_t size = stream.tellg();
  stream.seekg(0);
  if(size!=0)
  {
    std::unique_ptr<char[]> array(new char[size]);
    stream.read(array.get(), size);
    std::vector<char> vector_1(array.get(),array.get()+size);
    for (auto i = vector_1.begin(); i != vector_1.end();i++)
    {
      std::cout << *i;
    }
  }
  stream.close();
}
