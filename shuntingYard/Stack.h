#include "LNode.h"

class Stack {
 public:
  Stack();
  void push(char* node);
  void pop();
  char* top();
 private:
  LNode* head;
};
