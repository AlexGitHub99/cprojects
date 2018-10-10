#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct student {
  char first[10];
  char last[10];
  int id;
  float gpa;
};

void addStudent(vector<student*>* &studentList, char first[11], char last[11], int id, float gpa);
void printStudent(vector<student*>* &studentList);
void delStudent(vector<student*>* &studentList, int id);

int main() {
 
  vector<student*>* studentList = new vector<student*>(); //creates a new vector pointer of struct pointers on the heap

  cout << "Welcome to Student List! Commands: add, print, delete.";
  
  bool running = true;
  
  while(running == true) { // main loop
    char input[10]; 
    cin.get(input, 7);
    while(cin.get() != '\n');
    if(strcmp(input, "add") == 0) { //user typed add command

      char first[11];
      char last[11];
      int id = 0;
      float gpa;
      
      cout << "Please enter the students first name (10 letters or less)";   
      cin.get(first, 11);	
      while(cin.get() != '\n');

      cout << "Please enter the student last name (10 letters or less)";
      cin.get(last, 11);
      while(cin.get() != '\n');

      cout << "Please enter the students id (6 numbers)";
      char idText[7];
      cin.get(idText, 7);
      while(cin.get() != '\n');
      for(int i = 0; i < 6; i++) {
	//Friend: Nathan Class: C++ programming 6
	//I am using their idea with their permission
	//Their idea was to combine the integer values of each character of the id into a single integer by multiplying each by 10 to the power of it's place value, then adding them
	id += (idText[i] - 48) * pow (10, 5 - i);
	//end of code where idea was used
      }
      cout << id;

      
    }
  }
  /***
  addStudent(studentList, "Alex", "King", 351013, 4.218);
  addStudent(studentList, "Michael", "Kong", 32134823, 1.0);
  printStudent(studentList);
  delStudent(studentList, 351013);
  printStudent(studentList);
  ***/
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

  //vector<student*>::iterator it = studentList->begin();

  studentList->push_back (newStudent); //inserts newStudent after the last element in studentList

  /***
  cout << studentList << endl;
  
  cout << newStudent->first << endl;
  cout << newStudent->last << endl;
  cout << newStudent->id << endl;
  cout << newStudent->gpa << endl;
  ***/
  
}

void printStudent(vector<student*>* &studentList) {
  for(int i = 0; i < studentList->size(); i++) {
    cout << (*studentList)[i]->first << " " << (*studentList)[i]->last << ", ";
    cout << (*studentList)[i]->id << ", ";
    cout << (*studentList)[i]->gpa << endl;
  }
  cout << "this just ran" << endl;
}

void delStudent(vector<student*>* &studentList, int id) {
  for(int i = 0; i < studentList->size(); i++) {
    if((*studentList)[i]->id == id) {
      delete[] (*studentList)[i];
      studentList->erase (studentList->begin() + i);
    } 
  }
}
