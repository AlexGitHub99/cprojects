#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"
#include <cstdlib>

using namespace std;

class Node{
 public:
  Node(Student* newvalue);
  ~Node();
  Node* getNext();
  Student* getStudent();
  void setNext(Node* newnext);
private:
  Student* value;
  Node* next;
};

#endif
