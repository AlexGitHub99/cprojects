#include <iostream>
#include <cstring>
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
  char colorS[6];
  char newColorS[6];
  if(color == RED) {
    strcpy(colorS, "RED");
  } else {
    strcpy(colorS, "BLACK");
  }
  if(newColor == RED) {
    strcpy(newColorS, "RED");
  } else {
    strcpy(newColorS, "BLACK");
  }
  cout << "Changing color of " << this->getData() << " from " << colorS << " to " << newColorS << endl; 
  color = newColor;
}

void Node::setIsR(bool newIsR) {
  isR = newIsR;
}

void Node::setData(int newData) {
  data = newData;
}

Node::~Node() { //set parents corresponding child to NULL if node is deleted
  if(this->getParent() != NULL) {
    if(isR) { //Node is right
      this->getParent()->setRight(NULL);
    } else { //Node is left
      this->getParent()->setLeft(NULL);
    }
  }
}