#include "LNode.h"
#include <iostream>

using namespace std;

LNode::LNode() {
  next = NULL;
  data = NULL;
}

LNode* LNode::getNext() {
  return next;
}

void LNode::setNext(LNode* newNext) {
  next = newNext;
}

char* LNode::getData() {
  return data;
}

void LNode::setData(char* newData) {
  data = newData;
}
