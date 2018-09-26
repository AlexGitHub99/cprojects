#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

void addStudent(char first[10], char second[10], int id, float gpa);
void printStudent();
void delStudent(int id);

main() {
  
  struct student {
    char first[10];
    char second[10];
    int id;
    float gpa;
  }
  
  vector<*int> studentList;
  int *vectorPtr = &studentList;
  cout << vectorPtr << endl;
  

  
  
}
