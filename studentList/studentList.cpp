#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void addStudent(&vector<student*>*, char first[10], char second[10], int id, float gpa);
void printStudent();
void delStudent(int id);

struct student {
  char first[10];
  char second[10];
  int id;
  float gpa;
};

main() {
 
  vector<student*>* studentList = new vector<student*>(); //creates a new vector pointer of struct pointers on the heap
  cout << studentList;
  
}
