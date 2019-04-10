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
}
