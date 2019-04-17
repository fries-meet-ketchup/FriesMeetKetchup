
#include <string>
#ifndef HEAP_HPP
#define HEAP_HPP

struct Node
{
  string restaurantName;
  string type;
  string veggie;
  string country;
  string price;
  string city;
  double rating;
  int key; //count ++ 
  
  
};

class Heap {
private:
  Node* priorityQueue; //pointer to the array used to implement priority queue
  int currentQueueSize;
  int maxQueueSize;
  
  void repairUpward(int);
  void repairDownward(int);

public:
  Heap(int queueSize);
  ~Heap();
  void enqueue(string, string, string, string, string, string, double);
  void dequeue();
  Node peek();
  bool isFull();
  bool isEmpty();
  
  
  
};

#endif
