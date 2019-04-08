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
    if(strlen(cChar) > 1) { //cChar is a  number 
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
  cout << down->size();
  cout << left->size();
  while(left->top() != NULL) {
    cout << "Test";
    cout << left->top();
    left->pop();
  }
}

void transfer(Stack* source, Stack* destination) {
  
}
