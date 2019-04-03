#include <iostream>
#include "Node.h"

using namespace std;

Node::Node() {
  right = NULL;
  left = NULL;
  parent = NULL;
  data = 0;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getParent() {
  return parent;
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

void Node::setParent(Node* newParent) {
  parent = newParent;
}

void Node::setData(int newData) {
  data = newData;
}
