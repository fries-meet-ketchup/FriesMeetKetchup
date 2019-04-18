#include <iostream>
#include "project.hpp"

using namespace std;


  
Heap::Heap(int queueSize){
  maxQueueSize = queueSize;
  currentQueueSize = 0;
  priorityQueue = new Node[queueSize];
}

Heap::~Heap(){
  delete [] priorityQueue;
}

void swap(Node *x, Node *y)
{
    Node temp = *x;
    *x = *y;
    *y = temp;
}

int parent(int index)
{
 return (index-1)/2;
}

int leftChild(int index)
{
 return ((2*index) + 1);
}

int rightChild(int index)
{
 return ((2*index) + 2);
}

void Heap::enqueue(string _restaurant, double _rating){
  Node temp;
  temp.restaurant = _restaurant;
  temp.rating = _rating;
  if(isFull(){
    cout << "Heap full, cannot enqueue" << endl;
    return;
  }
  currentQueueSize++;
  int index = currentQueueSize - 1;
  priorityQueue[index] = temp;
  repairUpward(index);
}

void Heap::dequeue(){
  Node temp;
  if(currentQueueSize==0){
    cout<<"Heap empty, cannot dequeue"<<endl;
    return;
  }
  temp = heap[0];
  priorityQueue[0] = priorityQueue[currentQueueSize-1];
  currentQueueSize--;
  repairDownward(0);
}

Node Heap::peek(){
  if(isEmpty()){
      cout<< "Heap empty, nothing to peek" <<endl;
      Node node;
      node.restaurant = "";
      return node;
    }
    return priorityQueue[0];
}

bool Heap::isFull(){
  if(currentQueueSize != maxQueueSize){
    return false;
  }
  else{
    return true;
  }
}
  
bool Heap::isEmpty(){
  if(currentQueueSize == 0){
    return true;
  }
  else{
    return false;
  }
}

void Heap::repairUpward(int nodeIndex)
{
  while(nodeIndex != 0 && (priorityQueue[parent(nodeIndex)] > priorityQueue[nodeIndex])){
    swap(&priorityQueue[nodeIndex], &priorityQueue[parent(nodeIndex)]);
    nodeIndex = parent(nodeIndex);
  }
}

void Heap::repairDownward(int nodeIndex)
{
  int right = rightChild(nodeIndex);
  int left = leftChild(nodeIndex);
  int smallest = nodeIndex;
  if(left< currentSize && ((priorityQueue[left] < priorityQueue[nodeIndex]) || ( priorityQueue[left] == priorityQueue[nodeIndex])))
  {
    smallest = left;
  }
  if(right < currentSize &&((priorityQueue[right] < priorityQueue[smallest]) || ( priorityQueue[right] == priorityQueue[smallest])))
  {
    smallest = right;
  }
  if(smallest != nodeIndex){
    swap(&priorityQueue[nodeIndex], &priorityQueue[smallest]);
    nodeIndex = smallest;
  }
}

bool Heap::matching(string answer, ){
  if( answer == ){
    return true;
  }
  else{
    return false;
  }
}

int Heap::counting(Node ){
  
}
