#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>
//Created by: Alex King
//Last modified: 3/11/19

//student: Zareef
//Idea for storing binary tree as array

using namespace std;

void print(int tree[100]);

int main () {
  int tree[100];
  for(int i = 0; i < 100; i++) {
    tree[i] = -1;
  }
  
  char input[21];
  cout << "Would you like to enter numbers as console input or a file name? Type 'input' or 'file': ";
  cin.get(input, 10, '\n');
  while (cin.get() != '\n');
  if (strcmp(input, "input") == 0) {
    cout << "Enter up to 100 numbers, one at a time: ";
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
      print(tree);
      cout << endl;
      int i = 0;
      while(tree[i] != -1 and i < 100) {
	cout << tree[i] << ", ";
	i++;
      }
      cout << endl;
    }
  } else if (strcmp(input, "file") == 0) {
    cout << "Enter the file name: ";
    cin.get(input, 20,'\n');
    while(cin.get() != '\n');
    ifstream newFile(input);
    while(true) {
      newFile.get(input, 4, ' ');
      newFile.get();
      if(strlen(input) == 0) {
	break;
      }
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
    }
    print(tree);
    cout << endl;
    int i = 0;
    while(tree[i] != -1 and i < 100) {
      cout << tree[i] << ", ";
      i++;
    }
  }
  cout << endl;
}

void print(int tree[100]) {
  int level = 0;
  int width = 0;
  int i = 0;
  while(tree[i] != -1) {
    if(tree[i + 1] == -1 or i == 99) {
      width = 6 * pow (2, ceil (log2 (i + 2)) - 1); 
    }
    i++;
  }
  i = 0;
  while(tree[i] != -1) {
    for( int j = 0; j < floor ( floor ((width - ((pow (2, level)) * 4)) / ((pow (2, level))*2)) / 2); j++) {
      cout << " ";
    }
    for( int j = 0; j < ceil ( floor ((width - ((pow (2, level)) * 4)) / ((pow (2, level))*2)) / 2); j++) {
      cout << "-";
    }
    cout << tree[i];
    for(int j = 0; j < (3 - log10 (tree[i])); j++) {
      cout << "-";
    }
    for( int j = 0; j < floor ( ceil (((double)width - ((pow (2, level)) * 4)) / ((pow (2, level))*2)) / 2); j++) {
      cout << "-";
    }
    for( int j = 0; j < ceil (ceil (((double)width - ((pow (2, level)) * 4)) / ((pow (2, level))*2)) / 2); j++) {
      cout << " ";
    }
    
    if(pow (2, level + 1) - 2 == i) {
      cout << endl;
      level++;
    }
    i++;
  }
  cout << endl;
}

