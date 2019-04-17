#include <iostream>
#include "Node.h"

using namespace std;

void insert(Node* node);
void testAll(Node* node);
bool case1(Node* node);
bool case2(Node* node);
bool case3(Node* node);
bool case4(Node* node);
bool case5(Node* node);

const bool RED = true;
const bool BLACK = false;

int main() {
  cout << "Welcome to red black tree!" << endl;
  cout << "Commands:" << endl;
  return 0;
}

void insert(Node* current, Node* node) {
  if(node->getData() < current->getData()) {
    if(current->getLeft() != NULL) {
      insert(current->getLeft(), node);
    } else {
      current->setLeft(node);
      testAll(node);
    }
  }
  if(node->getData() >= current->getData()) {
    if(current->getRight() != NULL) {
      insert(current->getRight(), node);
    } else {
      current->setRight(node);
      testAll(node);
    }
  }
}
void testAll(Node* node) {
  if(case1(node)) {}
  else if(case2(node)) {}
  else if(case3(node)) {}
  else if(case4(node)) {};
}
	     
bool case1(Node* node) {
  if(node->getParent() == NULL) {
    node->setColor(BLACK);
    return true;
  }
  return false;
}

bool case2(Node* node) {
  if(node->getParent() != NULL) { //has parent
    if(node->getParent()->getParent() !=  NULL) { //has grandparent
      Node* grandFather = node->getParent()->getParent();
      if(grandFather->getRight() != NULL and grandFather->getLeft() != NULL) { //has uncle
        if(grandFather->getRight()->getColor() == RED && grandFather->getLeft()->getColor() == RED) { //parent and uncle are red
          grandFather->setColor(RED);
          //set parent and uncle to black
          grandFather->getRight()->setColor(BLACK);
          grandFather->getLeft()->setColor(BLACK);
          //test all cases again on grandfather
          testAll(grandFather);
          return true;
        } 
      }
    }
  }
  return false;
}

bool case3(Node* node) {
  if(node->getParent() != NULL) {
    if(node->getParent()->getParent() != NULL) {
      Node* grandfather = node->getParent()->getParent();
      if(node->getParent()->isLeft() and node->isRight())  {
        if(grandfather->getRight() != NULL) {
          if(grandfather->getRight()->getColor() == RED) {
            return false;
          }
          Node* tempLeft = node->getLeft();
          Node* tempParent = node->getParent();
          grandfather->setLeft(node);
          node->setLeft(tempParent);
          node->getLeft()->setRight(tempLeft);
          case4(node->getLeft());
          return true;
        }
      } else if(node->getParent()->isRight() and node->isLeft()) {
        if(grandfather->getLeft() != NULL) {
          if(grandfather->getLeft()->getColor() == RED) {
            return false;
          }
          Node* tempRight = node->getRight();
          Node* tempParent = node->getParent();
          grandfather->setRight(node);
          node->setRight(tempParent);
          node->getRight()->setLeft(tempRight);
          case4(node->getRight());
          return true;
        }
      }
    }
  }
  return false;
}

bool case4(Node* node) {
  return false;
}
