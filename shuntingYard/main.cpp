#include <iostream>
#include "Node.h"
#include <stack>

using namesapce std;

main () {
	stack down;
	stack right;
	cout << "Please enter a series of operations." << endl;
	cin.get(char* cChar, 10, ' ');
	if(cChar > 48 && cChar < 57 || cChar == '(') { // char is a number
		right.push(cChar);
	}
}

