#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
  right = NULL;
  left = NULL;
  data = 0;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}

int Node::getData() {
  return data;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

void Node::setData(int newData) {
  data = newData;
}