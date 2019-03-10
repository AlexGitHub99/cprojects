#include <iostream>
#include <cstring>
#include <cmath>

//student: Zareef
//Idea for storing binary tree as array

using namespace std;

void print(int tree[100]);

int main () {
	int tree[100];
	for(int i = 0; i < 100; i++) {
	  tree[i] = -1;
	}
	
	char input[11];
	cout << "Would you like to enter numbers as console input or a file name? Type 'input' or 'file'";
	cin.get(input, 10, '\n');
	while (cin.get() != '\n');
	if (strcmp(input, "input") == 0) {
		cout << "Enter up to 100 numbers one at a time";
		while (true) {
			cin.get(input, 10, '\n');
			while (cin.get() != '\n');
			int number = 0;
			for (int i = 0; i < strlen(input); i++) {
				number += (input[i] - 48) * pow(10, strlen(input) - i - 1);
			}
			for (int i = 0; i < 100; i++) {
				if (number > tree[i] || tree[i] == 0) {
					int temp = tree[i];
					tree[i] = number;
					number = temp;
				}
			}
			for (int i = 0; i < 10; i++) {
				cout << tree[i] << endl;
			}
			print(tree);
		}
	}
}

void print(int tree[100]) {
  int level = 0;
  int width = 0;
  int i = 0;
  while(tree[i] != -1) {
    if(tree[i + 1] == -1) {
      width = 5 * pow (2, ceil (log2 (i + 2)) - 1); 
    }
    i++;
   }
  for( int i = 0; i < 100; i++) {
    for( int j = 0; j < (width - ((level + 1) * 4)) / (pow (2, level) + 1); j++) {
      cout << "+";
    }
    cout << tree[i];
    for(int j = 0; j < (3 - log10 (tree[i])); j++) {
      cout << " ";
    }
    
    
    if(pow (2, level) - 1 == i) {
      cout << endl;
      level++;
    }
  }

}

