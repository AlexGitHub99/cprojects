#include <iostream>
#include "Node.h"
#include <stack>
#include <cstring>
using namespace std;

main () {
	stack<char> down;
	stack<char> left;
	cout << "Please enter a series of operations." << endl;
	char cChar[101];
	cin.get(cChar, 10, ' ');
	while(strlen(cChar) > 0) {
		if(strlen(cChar) > 1) { //cChar isa  number
			for(int i = 0; i < strlen(cChar); i++) {
				if(cChar[i] > 48 && cChar[i] < 57) { 
					left.push(cChar[0]);
					}
				}
			}
		else if(cChar[0] == '(') { // char is a left parenthasy
			left.push(cChar[0]);
		} else if (cChar[0] == ')') {//char is a right parenthasy
			left.push(down.top());
			down.pop();
		} else {
			down.push(cChar[0]);
		}
		cin.get(cChar, 10, ' ');

} for(int i = 0;i < left.size(); i ++ ) {
	cout << left.top();
	left.pop();
	}
}
