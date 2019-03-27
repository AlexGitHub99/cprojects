//Creator: Alex King
//Last Modified: 3/25/19
//This program builds a binary search tree
#include <iostream>
#include "Node.h"
#include <cstring>
#include <cmath>

using namespace std;

void add(Node* current, Node* newNode);
void del(Node* current, int number);
void print(Node* current, int depth);

Node* takeRight(Node* current);
Node* delNode(Node* node);

int main () {
    cout << "Welcome to binary search tree. Commands: " << endl;
    cout << "add <number> - add a number to the tree" << endl;
    cout << "del <numbers> - delete a number from the tree" << endl;
    cout << "print - prints the tree" << endl;
    cout << "quit - quit the program" << endl;


    Node* head = new Node();
    char input[10];

    bool cont = true;
    while(cont == true) {
        cin.getline (input, 10);
        cout << "User typed " << input << endl;

        if(strncmp(input, "add", 3) == 0) {
            int number = 0;
            number = atoi(&input[4]); //convert input characters to int
            Node* newNode = new Node();
            newNode->setData(number);
            add(head, newNode);
        } else if(strncmp(input, "del", 3) == 0) {
            int number = 0;
            number = atoi(&input[4]);
            del(head, number);
        } else if(strncmp(input, "print", 5) == 0) {
            cout << "Printing graph" << endl;
            print(head, 0);  
        } else if(strncmp(input, "quit", 4) == 0) {
            cont = false;
        }
    }
}

//adds a new node to the binary tree
void add(Node* current, Node* newNode) {
    if(current != NULL) {
        if(newNode->getData() < current->getData()) { 
            //smaller than current node
            if(current->getLeft() != NULL) {
                //already has a left node, recurse
                add(current->getLeft(), newNode); 
            } else {
                //add it to the left
                current->setLeft(newNode);
            }
        } else { 
            //larger than current node
            if(current->getRight() != NULL) { 
                //already has a right node, recurse
                add(current->getRight(), newNode);
            } else {
                //add it to the right
                current->setRight(newNode);
            }
        }
    }
}

//deletes a node with a certain number from the tree if found
void del(Node* current, int number) {
    if(current != NULL) {
        if(number < current->getData()) {
            //smaller than current node
            if(current->getLeft() != NULL) {
                //already has left node
                if(current->getLeft()->getData() == number) {
                    //left node is the number, delete left
                    current->setLeft(delNode(current->getLeft()));
                    cout << "Deleted number" << endl;
                } else {
                    //recurse
                    del(current->getLeft(), number);
                }
            } else {
                cout << "Number not in the tree" << endl;
            }
        } else if(number > current->getData()) {
            if(current->getRight() != NULL) {
                if(current->getRight()->getData() == number) {
                    current->setRight(delNode(current->getRight()));
                    cout << "Deleted number" << endl;
                } else {
                    //recurse
                    del(current->getRight(), number);
                }
            } else {
                cout << "Number not in the tree" << endl;
            }
        } else {
            //current node is number, delete it
            delNode(current);
            cout << "Deleted number" << endl;
        }       
    }
}

//returns the rightmost node from the passed in node and reconnects the node it was taken from
Node* takeRight(Node* current) {
    if(current->getRight() != NULL) {
        if(current->getRight()->getRight() != NULL) {
            return takeRight(current->getRight());
        } else {
            Node* temp = current->getRight();
            current->setRight(temp->getLeft());
            return temp;
        }
    } else {
        return current;
    }
}

//deletes a node and returns the in order successor
Node* delNode(Node* node) {
    if(node->getLeft() == NULL && node->getRight() == NULL) {
        delete node;
        return NULL;
    } else if (node->getRight() == NULL) {
        Node* temp = node->getLeft();
        delete node;
        return temp;
    } else if (node->getLeft() == NULL) {
        Node* temp = node->getRight();
        delete node;
        return temp;
    } else {
        Node* temp = takeRight(node);
        temp->setLeft(node->getLeft());
        temp->setRight(node->getRight());
        delete node;
        return temp;
    }
}

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