#include <iostream>
#include "Node.h"
#include "cstring"

using namespace std;

void insert(Node* current, int number);
void testAll(Node* node);
bool case1(Node* node);
bool case2(Node* node);
bool case3(Node* node);
bool case4(Node* node);
bool case5(Node* node);
void print(Node* current, int depth);
const bool RED = true;
const bool BLACK = false;

int main() {
  cout << "Welcome to red black tree!" << endl;
  cout << "Commands:" << endl;
  cout << "add <number>" << endl;
  cout << "print" << endl;
  cout << "quit" << endl;
  char input[21];
  Node* head = new Node(0);
  // bool cont = true;
  // while(cont) {
  //   //input = " ";
  //   cin.get(input, 20, ' ');
  //   cin.get();
  //   if(strcmp(input , "add") == 0) {
  //     cin.get(input, 20, '\n');
  //     cin.get();
  //     int number = atoi(input);
  //     Node* node = new Node();
  //     node->setData(number);
  //     insert(head, node);
  //   } else if(strcmp(input, "print") == 0) {
  //     print(head, 0);
  //   } else if(strcmp(input, "quit") == 0) {
  //     cont = false;
  //   } else {
  //     cout << "I dont know what this is " << input << endl;
  //   }
  // }

  //Most of print function copied from previous project
  bool cont = true;
  while(cont == true) {
      cin.getline (input, 20);

      if(strncmp(input, "add", 3) == 0) {
          int number = 0;
          number = atoi(&input[4]); //convert input characters to int
          insert(head, number);
      } else if(strncmp(input, "print", 5) == 0) {
          cout << "Printing graph" << endl;
          print(head, 0);  
      } else if(strncmp(input, "quit", 4) == 0) {
          cont = false;
      }
    }

  return 0;
}

void insert(Node* current, int number) {
  if(current->getData() == 0) {
      current->setData(number);
  } else if(number < current->getData()) {
    if(current->getLeft() != NULL) {
      insert(current->getLeft(), number);
    } else {
      current->setLeft(new Node(number));
      //testAll(node);
    }
  } else if(number >= current->getData()) {
    if(current->getRight() != NULL) {
      insert(current->getRight(), number);
    } else {
      current->setRight(new Node(number));
      //testAll(node);
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

//Copied from previous project binary tree
//prints out tree recursively
void print(Node* current, int depth) {
    cout << "(" << current->getData() << ")\n";
    if(current->getLeft() != NULL) {
        for(int i = 0; i < depth; i++) {
            cout << "    ";
        }
        cout << "(" << current->getData() << ")";
        cout << " L> ";
        print(current->getLeft(), depth + 1);
    }
    if(current->getRight() != NULL) {
        for(int i = 0; i < depth; i++) {
            cout << "    ";
        }
        cout << "(" << current->getData() << ")";
        cout << " R> ";
        print(current->getRight(), depth + 1);
    }
}