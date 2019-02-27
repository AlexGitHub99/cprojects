#include <iostream>
#include "Node.h"
#include "Stack.h"
#include <cstring>
using namespace std;

main () {
	Stack down;
	Stack left;
	cout << "Please enter a series of operations." << endl;
	char cChar[101];
	cin.get(cChar, 10, ' ');
	while(strlen(cChar) > 0) {
		if(strlen(cChar) > 1) { //cChar isa  number 
		  left.push(cChar);
		} else if(cChar[0] == '(') { // char is a left parenthasy
			left.push(cChar);
		} else if (cChar[0] == ')') {//char is a right parenthasy
			left.push(down.top());
			down.pop();
		} else {
			down.push(cChar);
		}
		cin.get(cChar, 10, ' ');

	}
	bool cont = true;
	while(cont == true) {
	  if(left.top() != NULL) {
	cout << left.top();
	left.pop();
	  } else {
	    cont = false;
	  }
	}
}
