//Author: Alex King
//Last modified: 7/3/19
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
bool del(Node* &head, int number);
Node* goRight(Node* current);
bool delCase1(Node* node);
bool testAllDel(Node* node);
bool delCase2(Node* node);
bool delCase3(Node* node);
bool delCase4(Node* node);
bool delCase5(Node* node);
bool delCase6(Node* node);
bool delCase7(Node* node);
void rotateR(Node* node);
void rotateL(Node* node);
void print(Node* current, int depth);
Node* resetHead(Node* head);

int main() {
  cout << "Welcome to red black tree!" << endl;
  cout << "Commands:" << endl;
  cout << "add <number>" << endl;
  cout << "read <filename>" << endl;
  cout << "search <number>" << endl;
  cout << "del <number>" << endl;
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
        Node* node = search(head, atoi(input + 7));
	if(node != NULL) {
	  cout << "Number is in tree" << endl;
	} else {
	  cout << "Number is not in tree" << endl;
	}
      } else if(strncmp(input, "del", 3) == 0) {
	Node* headChild = NULL;
	if(head->getRight() != NULL) {
	  headChild = head->getRight();
	} else if(head->getLeft() != NULL) {
	  headChild = head->getLeft();
	} else {
	  headChild = NULL;
	}
	if(del(head, atoi(input + 4)) == true) {
	  cout << "Deleted node successfully" << endl;
	} else {
	  cout << "Problem deleting node" << endl;
	}
	if(head == NULL) {
	  if(headChild == NULL) {
	    head = new Node(0, BLACK);
	  } else {
	    head = resetHead(headChild);
	  }
	} else {
	  head = resetHead(head);
	}
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
  return false;
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

bool del(Node* &head, int number) {
  Node* node = search(head, number);
  if(node != NULL) {
    Node* remNode = NULL;
    if(node->getLeft() != NULL && node->getRight() != NULL) {
      remNode = goRight(node->getLeft());
      node->setData(remNode->getData());
    } else {
      if(node == head) {
        head = NULL;
      }
      remNode = node;
    }
    return delCase1(remNode);
  }
  return false;
}

Node* goRight(Node* current) {
  if(current->getRight() != NULL) {
    return goRight(current->getRight());
  } else {
    return current;
  }
}

bool delCase1(Node* node) {
  bool output = false;
  Node* child = NULL;
  if(node->getRight() != NULL) {
    child = node->getRight();
  } else if(node->getLeft() != NULL) {
    child = node->getLeft();
  } else {
    if(node->getColor() == RED) {
      output = true;
      cout << "Deleting red node " << node->getData() << " with no children" << endl;
    } else {
      cout << "Deleting black node " << node->getData() << " with no children" << endl;
      output = testAllDel(node);
    }
    delete node;
    return output;
  }
  if(node->getParent() != NULL) {
    if(node->isRight()) {
      node->getParent()->setRight(child);
    } else {
      node->getParent()->setLeft(child);
    }
    node->setParent(NULL);
  } else {
    child->setParent(NULL);
  }
  if(node->getColor() == BLACK and child->getColor() == RED) {
    child->setColor(BLACK);
    output = true;
    cout << "Deleting black node " << node->getData() << " with red child" << endl;
  } else if(node->getColor() == BLACK and child->getColor() == BLACK) {
    cout << "Deleting black node " << node->getData() << " with black child" << endl;
    output = testAllDel(child);
  } else {
    cout << "Deleting red node " << node->getData() << " with black child" << endl;
    
  }
  delete node;
  return output;
}

bool testAllDel(Node* node) {
  if(delCase2(node)) {
    return true;
  }
  delCase3(node);
  if(delCase4(node)) {
    testAllDel(node->getParent());
    return true;
  }
  if(delCase5(node)) {
    return true;
  }
  delCase6(node);
  if(delCase7(node)) {
    return true;
  }
  return false;
}

//Case 2: Return true if node is root node, dont change tree
bool delCase2(Node* node) {
  cout << "Calling delCase 2 on node " << node->getData() << endl;
  if(node->getParent() == NULL) { //node is root node
      return true;
  } else { //node is not root node
      return false;
  }
}

//Case 3: If sibling is red, rotate sibling through parent and switch colors of parent and sibling
bool delCase3(Node* node) {
  cout << "Calling delCase 3 on node " << node->getData() << endl;
  Node* sibling = NULL;
  if(node->isRight()) {
    sibling = node->getParent()->getLeft();
    if(sibling->getColor() == RED) {
      rotateR(sibling);
    } else {
      return false;
    }
  } else if(node->isLeft()) {
    sibling = node->getParent()->getRight();
    if(sibling->getColor() == RED) {
      rotateL(sibling);
    } else {
      return false;
    }
  }
  node->getParent()->setColor(RED);
  sibling->setColor(BLACK);
  return true;
}

//Case 4: If sibling is black and has two black children, set sibling's color to red
bool delCase4(Node* node) {
  cout << "Calling delCase 4 on node " << node->getData() << endl;
  Node* sibling = NULL;
  if(node->getParent()->getColor() == BLACK) {
    if(node->isRight()) {
      if(node->getParent()->getLeft() != NULL) {
        sibling = node->getParent()->getLeft();
      }
    } else {
      if(node->getParent()->getRight() != NULL) {
        sibling = node->getParent()->getRight();
      }
    }
    if(sibling->getColor() == BLACK) {
      if(sibling->getLeft() != NULL) {
        if(sibling->getLeft()->getColor() == RED) {
          return false;
        }
      }
      if(sibling->getRight() != NULL) {
        if(sibling->getRight()->getColor() == RED) {
          return false;
        }
      }
      sibling->setColor(RED);
      return true;
    }
  }
  return false;
}

//Case 5: If parent is red, sibling is black, and sibling has two black children, set parent's color to black and sibling's color to red
bool delCase5(Node* node) {
  cout << "Calling delCase 5 on node " << node->getData() << endl;
  if(node->getParent()->getColor() == RED) {
    Node* sibling = NULL;
    if(node->isRight()) {
      sibling = node->getParent()->getLeft();
    } else {
      sibling = node->getParent()->getRight();
    }
    if(sibling->getColor() == BLACK) {
      if(sibling->getRight() != NULL) {
        if(sibling->getRight()->getColor() == RED) {
          return false;
        }
      }
      if(sibling->getLeft() != NULL) {
        if(sibling->getLeft()->getColor() == RED) {
          return false;
        }
      }
      node->getParent()->setColor(BLACK);
      sibling->setColor(RED);
      return true;
    }
  }
  return false;
}

//Case 6: If parent is black, sibling is black, 
//node is right and sibling's left is black and right is red OR node is left and sibling's left is red and right is black,
//rotate the sibling's red child through the sibling, set the old sibling's color to red and the new sibling's color to black
bool delCase6(Node* node) {
  cout << "Calling delCase 6 on node " << node->getData() << endl;
  if(node->getParent()->getColor() == BLACK) {
    Node* sibling = NULL;
    if(node->isRight()) {
      sibling = node->getParent()->getLeft();
      if(sibling->getColor() == BLACK) {
        if(sibling->getRight() != NULL) {
          if(sibling->getRight()->getColor() == RED) {
            if(sibling->getLeft() != NULL) {
              if(sibling->getLeft()->getColor() == RED) {
                return false;
              }
            }
            rotateL(sibling->getRight());
            sibling->setColor(RED);
            sibling->getParent()->setColor(BLACK);
            return true;
          } 
        }
      }
    } else {
      sibling = node->getParent()->getRight();
      if(sibling->getColor() == BLACK) {
        if(sibling->getLeft() != NULL) {
          if(sibling->getLeft()->getColor() == RED) {
            if(sibling->getRight() != NULL) {
              if(sibling->getRight()->getColor() == RED) {
                return false;
              }
            }
            rotateR(sibling->getLeft());
            sibling->setColor(RED);
            sibling->getParent()->setColor(BLACK);
            return true;
          }
        }
      }
    }
  }
  return false;
}

//Case 7: If sibling is black,
//node is right and sibling has a red left child OR node is left and sibling has a red right child,
//rotate the sibling through the parent, switch the colors of the parent and old sibling, and set the new sibling's color to black
bool delCase7(Node* node) {
  cout << "Calling delCase 7 on node " << node->getData() << endl;
  Node* sibling = NULL;
  if(node->isRight()) {
    sibling = node->getParent()->getLeft();
    if(sibling->getColor() == BLACK) {
      if(sibling->getLeft() != NULL) {
        if(sibling->getLeft()->getColor() == RED) {
          rotateR(sibling);
          sibling->setColor(node->getParent()->getColor());
          node->getParent()->setColor(BLACK);
          sibling->getLeft()->setColor(BLACK);
          return true;
        }
      }
    }
  } else {
    sibling = node->getParent()->getRight();
    if(sibling->getColor() == BLACK) {
      if(sibling->getRight() != NULL) {
        if(sibling->getRight()->getColor() == RED) {
          rotateL(sibling);
          sibling->setColor(node->getParent()->getColor());
          node->getParent()->setColor(BLACK);
          sibling->getRight()->setColor(BLACK);
          return true;
        }
      }
    }
  }
  return false;
}

//Rotate right, inputed node must be left of the parent it's rotating through
void rotateR(Node* node) {
  cout << "Rotating right through " << node->getParent()->getData() << endl;
  Node* tempRight = node->getRight();
  Node* tempParent = node->getParent();
  //If grandfather exists, set grandfather's corresponding child to the node instead of the parent
  if(node->getParent()->getParent() != NULL) {
    Node* grandfather = node->getParent()->getParent();
    if(node->getParent()->isRight()) {
      grandfather->setRight(node);
    } else {
      grandfather->setLeft(node);
    }
  } else {
    node->setParent(NULL);
  }
  node->setRight(tempParent);
  node->getRight()->setLeft(tempRight);  
}

//Rotate left, inputed node must be right of the parent it's rotating through
void rotateL(Node* node) {
  cout << "Rotating left through " << node->getParent()->getData() << endl;
  Node* tempLeft = node->getLeft();
  Node* tempParent = node->getParent();
  //If grandfather exists, set grandfather's corresponding child to the node instead of the parent
  if(node->getParent()->getParent() != NULL) {
    Node* grandfather = node->getParent()->getParent();
    if(node->getParent()->isRight()) {
      grandfather->setRight(node);
    } else {
      grandfather->setLeft(node);
    }
  } else {
    node->setParent(NULL);
  }
  node->setLeft(tempParent);
  node->getLeft()->setRight(tempLeft);
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
