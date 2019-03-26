#include <iostream>
#include "Node.h"
#include <cstring>
#include <cmath>

using namespace std;

void add(Node* current, Node* newNode);
void del(Node* current, int number);

int main () {
    cout << "Welcome to binary search tree. Commands: " << endl;
    cout << "add <number> - add a number to the tree" << endl;
    cout << "delete <numbers> - delete a number from the tree" << endl;
    cout << "quit - quit the program" << endl;

    Node* head = new Node();
    char input[10];
    cin.get(input, 8, ' ');

    if(strcmp(input, "add") == 0) {
        cin.get(input, 3, ' ');
        int number = 0;
        for(int i = 0; i < strlen(input); i++ ) {
            number+= (input[i] - 48) * pow (10, strlen(input) - i - 1);   
        }
        Node* newNode = new Node();
        newNode->setData(number);
        add(head, newNode);
    }
}

void add(Node* current, Node* newNode) {
    if(current != NULL) {
        if(newNode->getData() < current->getData()) {
            if(current->getLeft() != NULL) {
                add(current->getLeft(), newNode); 
            } else {
                current->setLeft(newNode);
            }
        } else {
            if(current->getRight() != NULL) {
                add(current->getRight(), newNode);
            } else {
                current->setRight(newNode);
            }
        }
    }
}

void del(Node* current, int number) {
    if(current != NULL) {
        if(number < current->getData()) {
            if(current->getLeft() != NULL) {
                if(current->getLeft()->getLeft() == NULL && current->getLeft()->getRight() == NULL) {
                    delete current->getLeft();
                } else if (current->getLeft()->getRight() == NULL) {
                    Node* temp = current->getLeft()->getLeft();
                    delete current->getLeft();
                    current->setLeft(temp);
                } else if (current->getLeft()->getLeft() == NULL) {
                    Node* temp = current->getLeft()->getRight();
                }
            }
        } else if(number < current->getData()) {
            if(current->getRight() != NULL) {
                    del(current->getRight(), number);
            }
        } else {
            if(current->getRight() == NULL && current->getLeft() == NULL) {
                delete current;
            } else if (current->getRight == NULL) {
                
            }
        }       
    }
}