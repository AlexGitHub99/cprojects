#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int newData, bool newColor) {
  right = NULL;
  left = NULL;
  parent = NULL;
  color = newColor;
  data = newData;
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

bool Node::getColor() {
  return color;
}

char Node::getColorChar() {
  if(color == RED) {
    return 'r';
  } else {
    return 'b';
  }
}

bool Node::isRight() {
  return isR;
}

bool Node::isLeft() {
  return !isR;
}

int Node::getData() {
  return data;
}

void Node::setRight(Node* newRight) {
  right = newRight;
  if(right != NULL) {
    right->setIsR(true);
    right->setParent(this);
  }
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
  if(left != NULL) {
    left->setIsR(false);
    left->setParent(this);
  }
}

void Node::setParent(Node* newParent) {
  parent = newParent;
}

void Node::setColor(bool newColor) {
  color = newColor;
}

void Node::setIsR(bool newIsR) {
  isR = newIsR;
}

void Node::setData(int newData) {
  data = newData;
}
