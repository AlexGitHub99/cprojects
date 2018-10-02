#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

struct student {
  char first[10];
  char last[10];
  int id;
  float gpa;
};

void addStudent(vector<student*>* &studentList, char first[10], char last[10], int id, float gpa);
void printStudent(vector<student*>* &studentList);
void delStudent(vector<student*>* &studentList, int id);

int main() {
 
  vector<student*>* studentList = new vector<student*>(); //creates a new vector pointer of struct pointers on the heap
  cout << studentList << endl;
  addStudent(studentList, "Alex", "King", 351013, 4.218);
  addStudent(studentList, "Michael", "Kong", 32134823, 1.0);
}

void addStudent(vector<student*>* &studentList, char first[10], char last[10], int id, float gpa) {
  student* newStudent = new student;

  for(int i = 0; i < 10; i++ ) { //sets the first name of the student struct to the passed in value
    newStudent->first[i] = first[i];
  }

  for(int i = 0; i < 10; i ++) { //sets the last name of the student struct to the passed in value
    newStudent->last[i] = last[i];
  }

  newStudent->id = id;
  newStudent->gpa = gpa;
  
  cout << newStudent->first << endl;
  cout << newStudent->last << endl;
  cout << newStudent->id << endl;
  cout << newStudent->gpa << endl;
  
  
}
