#include <vector>
#include "tasks.hpp"
#include "impl.hpp"

void fillRandom(double *array,size_t size)
{
  for(size_t i=0; i<size;i++)
  {
    array[i]=(rand() % 11) * 0.2 - 1;
  }
}

void lab_1::doFourthTask(const char* order, const char* vector_size)
{
  bool is_ascending=checkOrder(order);
  size_t size = atoi(vector_size);
  if (size <= 0)
  {
    throw std::invalid_argument("Invalid vector size");
  }
  std::vector<double> vector(size);
  fillRandom(vector.data(), size);
  print(vector);
  sort<BracketsAccess>(vector, is_ascending);
  print(vector);
}
