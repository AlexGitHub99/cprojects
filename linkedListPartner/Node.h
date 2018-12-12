//Node class of linked list. Contains a student pointer and a pointer to the next node in the list, and getters and setters
#include <iostream>
#include "Student.h"

class Node {
 public:
  Node(Student* newValue);
  ~Node();
  void setNext(Node* next);
  Student* getValue();
  Node* getNext();
 private:
  Student* value;
  Node* next;
};
