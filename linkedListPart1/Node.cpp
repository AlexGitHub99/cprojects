#include <iostream>
#include "Node.h"

Node::Node(Student* newValue) {//constructor
  value = newValue;
  next = NULL;
}

void Node::setNext(Node* newNext) {
  next = newNext;
}
  
Student* Node::getValue() {
  return value;
}

Node* Node::getNext() {
  return next;
}

Node::~Node() {//destructor
  delete &value;
  next = NULL;
}
