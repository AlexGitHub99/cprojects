#include "LNode.h"

class Stack {
 public:
  Stack();
  void push(char* node);
  void pop();
  char* top();
  int size();
 private:
  int sizeR(LNode* next, int count);
  LNode* head;
};
