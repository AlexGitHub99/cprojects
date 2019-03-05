#include <iostream>
#include <cstring>
#include <cmath>

//student: Zareef
//Idea for storing binary tree as array

using namespace std;

int main () {
	int tree[1000];
	char input[11];
	cout << "Would you like to enter numbers as console input or a file name? Type 'input' or 'file'";
	cin.get(input, 10, '\n');
	while (cin.get() != '\n');
	if (strcmp(input, "input") == 0) {
		cout << "Enter up to 100 numbers one at a time";
		cin.get(input, 10, '\n');
		while (cin.get() != '\n');
		int number = 0;
		for (int i = 0; i < strlen(input);  i++) {
			number+= (input[i] - 48) * pow(10, strlen(input) - i - 1);
		}
		for (int i = 0; i sizeOf(tree); i++) {
			if (number > tree[i] || tree[i] == 0) {
				int temp = tree[i];
				tree[i] = number;
				number = temp;
			}
	}

}

