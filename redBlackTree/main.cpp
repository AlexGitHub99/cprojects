#include <iostream>
#include "Node.h"

using namespace std;

bool isCase1(Node* node);
bool isCase2(Node* node);
bool isCase3(Node* node);
bool isCase4(Node* node);
bool isCase5(Node* node);
void case1(Node* node);
void case2(Node* node);
void case3(Node* node);
void case4(Node* node);
void case5(Node* node);

int main() {
  cout << "Welcome to red black tree!" << endl;
  cout << "Commands:" << endl;
  return 0;
}

bool isCase1(Node* head, Node* node) {
  if(node == head) {
    return true;
  }
}
