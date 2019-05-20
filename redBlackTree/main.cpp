//Author: Alex King
//Last modified: 4/17/19
//This program creates a self balancing red black tree from console input
//and prints it out.
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include "Node.h"

using namespace std;

void insert(Node* current, int number);
void testAll(Node* node);
bool case1(Node* node);
bool case2(Node* node);
bool case3(Node* node);
bool case4(Node* node);
bool case5(Node* node);
Node* search(Node* current, int number);
bool del(Node* head, int number);
Node* goRight(Node* current);
bool delCase1(Node* node);
bool delCase2(Node* node);
void print(Node* current, int depth);
Node* resetHead(Node* head);

int main() {
  cout << "Welcome to red black tree!" << endl;
  cout << "Commands:" << endl;
  cout << "add <number>" << endl;
  cout << "read <filename>" << endl;
  cout << "search <number>" << endl;
  cout << "print" << endl;
  cout << "quit" << endl;
  char input[21];
  Node* head = new Node(0, BLACK);

  //Most of print function copied from previous project, binary search tree
  bool cont = true;
  while(cont == true) {
      cin.getline (input, 20);

      if(strncmp(input, "add", 3) == 0) { //user typed "add" 
          int number = atoi(input + 4); //convert input characters to int
          insert(head, number);
          head = resetHead(head);
      } else if(strncmp(input, "read", 4) == 0) { //user typed "read"
          ifstream file;
          file.open(input + 5);
          while(true) {
            file.get(input, 3, ',');
            file.get();
            if(strlen(input) == 0) {
              break;
            } else {
              int number = atoi(input);
              insert(head, number);
              head = resetHead(head);
            }
          }
      } else if(strncmp(input, "search", 6) == 0) {
        Node* node = search(head, atoi(input + 8));
	if(node != NULL) {
	  cout << "Number is in tree";
	} else {
	  cout << "Number is not in tree";
	}
      } else if(strncmp(input, "del", 3) == 0) {
        
      } else if(strncmp(input, "print", 5) == 0) { //user typed "print"
          cout << "Printing graph" << endl;
          print(head, 0);  
      } else if(strncmp(input, "quit", 4) == 0) { //user typed "quit"
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
      Node* newNode = new Node(number, RED);
      current->setLeft(newNode);
      testAll(newNode);
    }
  } else if(number >= current->getData()) {
    if(current->getRight() != NULL) {
      insert(current->getRight(), number);
    } else {
      Node* newNode = new Node(number, RED);
      current->setRight(newNode);
      testAll(newNode);
    }
  }
}
void testAll(Node* node) {
  if(case1(node)) {}
  else if(case2(node)) {}
  else if(case3(node)) {}
  else if(case4(node)) {}
  else if(case5(node)) {};
}

bool case1(Node* node) {
  if(node->getParent() == NULL) {
    node->setColor(BLACK);
    return true;
  }
  return false;
}

bool case2(Node* node) {
  if(node->getParent() != NULL) {
    if(node->getParent()->getColor() == BLACK) {
      return true;
    }
  }
}

bool case3(Node* node) {
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

bool case4(Node* node) {
  if(node->getParent() != NULL) {
    if(node->getParent()->getParent() != NULL) {
      Node* grandfather = node->getParent()->getParent();
      if(node->getParent()->isLeft() and node->isRight())  {
        if(grandfather->getRight() != NULL) {
          if(grandfather->getRight()->getColor() == RED) {
            return false;
          }
        }
        Node* tempLeft = node->getLeft();
        Node* tempParent = node->getParent();
        grandfather->setLeft(node);
        node->setLeft(tempParent);
        node->getLeft()->setRight(tempLeft);
        case5(node->getLeft());
        return true;
      } else if(node->getParent()->isRight() and node->isLeft()) {
        if(grandfather->getLeft() != NULL) {
          if(grandfather->getLeft()->getColor() == RED) {
            return false;
          }
        }
        Node* tempRight = node->getRight();
        Node* tempParent = node->getParent();
        grandfather->setRight(node);
        node->setRight(tempParent);
        node->getRight()->setLeft(tempRight);
        case5(node->getRight());
        return true;
      }
    }
  }
  return false;
}

bool case5(Node* node) {
  if(node->getParent() != NULL) {
    if(node->getParent()->getParent() != NULL) {
      Node* grandfather = node->getParent()->getParent();
      if(node->getParent()->isLeft() and node->isLeft())  {
        if(grandfather->getRight() != NULL) {
          if(grandfather->getRight()->getColor() == RED) {
            return false;
          }
        }
        Node* tempParentRight = node->getParent()->getRight();
	if(grandfather->getParent() != NULL) {
	  if(grandfather->isRight()) {
	    grandfather->getParent()->setRight(node->getParent());
	  } else {
	    grandfather->getParent()->setLeft(node->getParent());
	  }
	} else {
	  node->getParent()->setParent(NULL);
	}
	node->getParent()->setRight(grandfather);
	grandfather->setLeft(tempParentRight);
	node->getParent()->setColor(!node->getParent()->getColor());
	grandfather->setColor(!grandfather->getColor());
        return true;
      } else if(node->getParent()->isRight() and node->isRight()) {
        if(grandfather->getLeft() != NULL) {
          if(grandfather->getLeft()->getColor() == RED) {
            return false;
          }
        }
        Node* tempParentLeft = node->getParent()->getLeft();
	if(grandfather->getParent() != NULL) {
	  if(grandfather->isRight()) {
	    grandfather->getParent()->setRight(node->getParent());
	  } else {
	    grandfather->getParent()->setLeft(node->getParent());
	  }
	} else {
	  node->getParent()->setParent(NULL);
	}
	node->getParent()->setLeft(grandfather);
	grandfather->setRight(tempParentLeft);
	node->getParent()->setColor(!node->getParent()->getColor());
	grandfather->setColor(!grandfather->getColor());
        return true;
      }
    }
  }
  return false;
}

Node* search(Node* current, int number) {
  if(number < current->getData()) {
    if(current->getLeft() != NULL) {
      return search(current->getLeft(), number);
    } else {
      return NULL;
    }
  } else if(number > current->getData()) {
    if(current->getRight() != NULL) {
      return search(current->getRight(), number);
    } else {
      return NULL;
    }
  } else {
    return current;
  }
}

bool del(Node* head, int number) {
  Node* node = search(head, number);
  if(node != NULL) {
    if(node->getLeft() != NULL) {
      Node* successor = goRight(node->getLeft());
    }
  }
}

Node* goRight(Node* current) {
  if(current->getRight() != NULL) {
    return goRight(current->getRight());
  } else {
    return current;
  }
}

bool delCase1(Node* node) {
  Node* child;
  if(node->getRight() != NULL) {
    child = node->getRight();
  } else if(node->getLeft() != NULL) {
    child = node->getLeft();
  } else {
    return false;
  }
  if(node->getParent() != NULL) {
    if(node->isRight()) {
      node->getParent()->setRight(child);
    } else {
      node->getParent()->setLeft(child);
    }
  } else {
    child->setParent(NULL);
  }
  if(node->getColor() == BLACK and child->getColor() == RED) {
    child->setColor(BLACK);
  } else if(node->getColor() == BLACK and child->getColor() == BLACK) {
    delCase2(child);
  }
  delete node;
  return true;
}
//Case 2: Return true if node is root node, dont change tree
bool delCase2(Node* node) {
  if(node->getParent() == NULL) { //node is root node
      return true;
  } else { //node is not root node
      return false;
  }
}

//Copied from previous project binary tree
//prints out tree recursively
void print(Node* current, int depth) {
    cout << "(" << current->getData() << current->getColorChar() << ")\n";
    if(current->getLeft() != NULL) {
        for(int i = 0; i < depth; i++) {
            cout << "        ";
        }
        cout << " LEFT> ";
        print(current->getLeft(), depth + 1);
    }
    if(current->getRight() != NULL) {
        for(int i = 0; i < depth; i++) {
            cout << "        ";
        }
        cout << " RIGHT> ";
        print(current->getRight(), depth + 1);
    }
}

Node* resetHead(Node* head) {
  while(head->getParent() != NULL) {
    head = head->getParent();
  }
  return head;
}
