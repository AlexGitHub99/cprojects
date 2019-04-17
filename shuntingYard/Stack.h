#ifndef STACK_H
#define STACK_H

#include "LNode.h"

class Stack {
 public:
  Stack();
  void push(char* node);
  void pop();
  char* top();
  int size();
 private:
  LNode* head;
  int sizeR(LNode* next, int count);
};

#endif
