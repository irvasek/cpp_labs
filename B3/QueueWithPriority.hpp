#ifndef QUEUE_WITH_PRIORITY_HPP
#define QUEUE_WITH_PRIORITY_HPP

#include <list>
#include <string>
#include <stdexcept>

typedef enum
{
  LOW,
  NORMAL,
  HIGH
} ElementPriority;

typedef struct
{
  std::string name;
} QueueElement;

template<typename ElementType>
class QueueWithPriority
{
public:
  void putElementToQueue(const ElementType& element, ElementPriority priority) noexcept;
  ElementType getElementFromQueue();
  void accelerate() noexcept;
private:
  std::list<ElementType> high_priority_queue_;
  std::list<ElementType> normal_priority_queue_;
  std::list<ElementType> low_priority_queue_;
};

template<typename ElementType>
void QueueWithPriority<ElementType>::putElementToQueue(const ElementType& element, ElementPriority priority) noexcept
{
  switch(priority)
  {
  case ElementPriority::HIGH:
    high_priority_queue_.push_back(element);
    break;
  case ElementPriority::NORMAL:
    normal_priority_queue_.push_back(element);
    break;
  case ElementPriority::LOW:
    low_priority_queue_.push_back(element);
    break;
  }
}
template<typename ElementType>
ElementType QueueWithPriority<ElementType>::getElementFromQueue()
{
  if(!high_priority_queue_.empty())
  {
    ElementType tmp = high_priority_queue_.front();
    high_priority_queue_.pop_front();
    return tmp;
  } else if(!normal_priority_queue_.empty())
  {
    ElementType tmp = normal_priority_queue_.front();
    normal_priority_queue_.pop_front();
    return tmp;
  } else if(!low_priority_queue_.empty())
  {
    ElementType tmp = low_priority_queue_.front();
    low_priority_queue_.pop_front();
    return tmp;
  } else
  {
    throw std::out_of_range("Queue is empty");
  }
}
template<typename ElementType>
void QueueWithPriority<ElementType>::accelerate() noexcept
{
  high_priority_queue_.splice(high_priority_queue_.end(), low_priority_queue_);
}

#endif // QUEUE_WITH_PRIORITY_HPP
