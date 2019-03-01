#include <iostream>
#include "Node.h"
#include <cstring>

//student: Zareef
//Idea for storing binary tree as array

using namespace std;

int main {
	char input[11];
	cout << "Would you like to enter numbers as console input or a file name? Type 'input' or 'file'"
	cin.get(input, 10, '\n');
	if (strcmp(input, "input") == 0) {
		cout << "Enter up to 100 numbers one at a time";
	}

}

