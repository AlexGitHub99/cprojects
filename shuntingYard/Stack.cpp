#include "Stack.h"
#include <iostream>

Stack::Stack() {
  head = NULL;
}

void Stack::push(char* data) {
  LNode* node = new LNode();
  node->setData(data);
  node->setNext(head);
  head = node;
}

void Stack::pop() {
  LNode* temp = head;
  head = head->getNext();
  delete temp;
}

char* Stack::top() {
  if(head != NULL) {
    return head->getData();
  } else {
    return NULL;
  }
}

int Stack::size() {
  return sizeR(head, 0);
}

int sizeR(LNode* next, int count) {
  count++;
  if(next->getNext() != NULL) {
    return sizeR(next->getNext(), count);
  } else {
    return count;
  }
}
