//Created by: Alex King
//Last Modified: 4/8/19
//This program takes in a series of operations and uses the shunting yard algorthmn to translate it into postfix notation
//and store in an expression tree. It can then be outputted in infix, prefix, or postfix notation.
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <cstring>
using namespace std;

main () {
  Stack* down = new Stack();
  Stack* left = new Stack();
  cout << "Please enter a series of operations." << endl;
  char cChar[20];
  cin.get(cChar, 10, ' ');
  cin.get();
  while(strlen(cChar) > 0) {
    if(strlen(cChar) > 1) { // char is a number 
      left->push(strcpy(new char[20], cChar));
    } else if(cChar[0] == '(') { // char is a left parenthasy
      left->push(strcpy(new char[20], cChar));
    } else if (cChar[0] == ')') {//char is a right parenthasy
      left->push(strcpy(new char[20], down->top()));
      down->pop();
    } else {
      down->push(strcpy(new char[20], cChar));
    }
    cin.get(cChar, 10, ' ');
    cin.get();
  }
  //while(left->top() != NULL) { //Prints out the expression in postfix notation
  //  cout << left->top();
  //  left->pop();
  //}
}

void transfer(Stack* source, Stack* destination) {
  
}
