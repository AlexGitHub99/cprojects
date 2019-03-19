5A#include "Node.h"

Node::Node() {
  right = NULL;
  left = NULL;
  data = NULL;
}

Node::getRight() {
  return right;
}

Node::getLeft() {
  return left;
}

Node::getData() {
  return data;
}

Node::setRight(Node* newRight) {
  right = newRight;
}

Node::setLeft(Node* newLeft) {
  left = newLeft;
}
