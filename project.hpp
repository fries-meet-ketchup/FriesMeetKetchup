
#ifndef HEAP_HPP
#define HEAP_HPP

struct Node
{
  std::string resturantName;
  int size;
  
};

class Heap {
private:
  Node* priorityQueue; //pointer to the array used to implement priority queue
  int currentQueueSize;
  int maxQueueSize;

public:
  Heap(int queueSize);
  ~Heap();
  
  
};

#endif
