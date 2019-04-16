#include <iostream>
#include "Node.h"

using namespace std;

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
}

bool case2(Node* node) {
  if(node->getParent() != NULL) { //has parent
    if(node->getParent()->getParent() !=  NULL) { //has grandparent
      Node* grandFather = node->getParent()->getParent();
      if(grandFather->getRight() != NULL and grandFather->getLeft() != NULL) { //has uncle
        if(grandFather->getRight()->getColor() == RED && grandFather->getLeft()->getColor() == RED) { //parent and uncle are red
          grandFather->setColor(RED);
          //set parent and uncle to red
          grandFather->getRight()->setColor(BLACK);
          grandFather->getLeft()->setColor(BLACK);
          //test all cases again on grandfather
          testAll(grandFather);
        } 
      }
    }
  }
}

bool case3(Node* node) {
  if(node->getParent() != NULL) {
    if(node->getParent()->getParent() != NULL {
	Node* grandFather = node->getParent() != NULL;
	if(node->getParent()->isLeft()) {
	   if(grandfather->getRight() != NULL) {
	     if(grandfather->getRight()->getColor() == RED) {
	       return false;
	     }
	     Node* tempLeft = node->getLeft();
	     Node* tempParent = node->getParent();
	     grandFather->setLeft(node);
	     node->setLeft(tempParent);
	     node->getLeft()->setRight(tempLeft);
	     return true;
	} else if(node->getParent()->isRight() and grandFather->getLeft()->getColor() == BLACK) {
	  if(node->isLeft()) {

	}
      }
  }
}

bool case4(Node* node) {
  
}
