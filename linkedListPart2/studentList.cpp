/***
Author: Alex King
Last modified: 10/10/18
This program stores a list of students using a vector pointer of struct pointers. Each struct contains a first name, last name, id, and gpa.
Users can type in command add, print, delete, and quit.
 ***/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <ios>
#include "Student.cpp"

using namespace std;

struct student {
  char first[10];
  char last[10];
  int id;
  float gpa;
};

void addStudent(Node* head, char first[11], char last[11], int id, float gpa);
void printStudent(Node* head);
bool delStudent(Node* head, int id);

int main() {
  //I got this code from stack overflow user:Melebius
  //http://stackoverflow.com/questions/14369673/round-double-to-3-points-decimal
  cout.setf(ios::fixed); //makes the significant digit precision for floats be followed exactly, inserting trailing zeroes if needed
  cout.precision(2); //sets the significant digits for floats to 2
  //End of used code
  
  vector<student*>* studentList = new vector<student*>(); //creates a new vector pointer of struct pointers on the heap

  cout << "Welcome to Student List! Commands:" << endl << "add - add a student" << endl << "print - prints all students" << endl << "delete - delete a student" << endl << "quit - quit the program" << endl;
  
  bool running = true;
  
  while(running == true) { // main loop
    char input[10]; 
    cin.get(input, 7);
    while(cin.get() != '\n');
    if(strcmp(input, "add") == 0) { //user typed add command

      char first[11];
      char last[11];
      int id = 0;
      float gpa = 0.00;
      
      cout << "Please enter the students first name (10 letters or less): ";   
      cin.get(first, 11);	
      while(cin.get() != '\n');

      cout << "Please enter the student last name (10 letters or less): ";
      cin.get(last, 11);
      while(cin.get() != '\n');
      
      cout << "Please enter the students id (6 numbers): ";
      char idText[7];
      
      bool correct = false;
      while(correct == false) {//keep taking input until the id format is correct
	cin.get(idText, 7);
	while(cin.get() != '\n');
	correct = true;
	for(int i = 0; i < 6; i++) {
	  if(idText[i] < 48 || idText[i] > 57) { //if any character of the id does not fall within the ascii range of a number than correct is set to false
	    correct = false;
	  }
	}
	if(correct == false) {
	  cout << "Please enter the students id correctly (6 numbers): ";
	}
      }
      
      for(int i = 0; i < 6; i++) {
	//Friend: Nathan Class: C++ programming 6
	//I am using their idea with their permission
	//Their idea was to combine the integer values of each character of the id into a single integer by multiplying each by 10 to the power of it's place value, then adding them
	id += (idText[i] - 48) * pow (10, 5 - i);
	//end of code where idea was used
      }
      
      

      cout << "Please enter the students gpa: ";
      char gpaText[6] = {'\0', '\0', '\0', '\0', '\0', '\0'};

      correct = false;
      while(correct == false) {
	cin.get(gpaText, 6);
	while(cin.get() != '\n');
	if(gpaText[0] >= 48 && gpaText[0] <= 57 && //the first character of the gpa must be a number
	   (gpaText[1] == '.' || gpaText[1] == '\0') && //the second character must be either a '.' or empty
	   ((gpaText[2] >= 48 && gpaText[2] <= 57) || gpaText[2] == '\0') && //the third character must be either a number or a null terminating character
	   ((gpaText[3] >= 48 && gpaText[3] <= 57) || gpaText[3] == '\0') && //the fourth character must be either a number or a null terminating character
	   ((gpaText[4] >= 48 && gpaText[4] <= 57) || gpaText[4] == '\0')) {  //the fifth chracter must be either a number or a null terminating character
	     //convert the ascii values of each character to integers then multiply by their corresponding place in relation to the decimal and add them
	     gpa += gpaText[0] - 48;
	     if(gpaText[2] != '\0') { gpa += (gpaText[2] - 48) * 0.1; }
	     if(gpaText[3] != '\0') { gpa += (gpaText[3] - 48) * 0.01; }
	     if(gpaText[4] != '\0') { gpa += (gpaText[4] - 48) * 0.001; }
	     correct = true;
	} else {
	  cout << "Please enter the gpa in the correct format, for example, 3.92: ";
	}
      }

      
      addStudent(studentList, first, last, id, gpa);
      cout << "Added " << first << " " << last << " with id " << id << " and gpa " << gpa << endl;
    }
    
    if(strcmp(input, "print") == 0) { //user typed print command
      printStudent(studentList);
    }

    if(strcmp(input, "delete") == 0) { //user typed delete command
      int id = 0;
      
      cout << "Please enter the students id (6 numbers): ";
      char idText[7];
      
      bool correct = false;
      while(correct == false) {//keep taking input until the id format is correct
	cin.get(idText, 7);
	while(cin.get() != '\n');
	correct = true;
	for(int i = 0; i < 6; i++) {
	  if(idText[i] < 48 || idText[i] > 57) { //if any character of the id does not fall within the ascii range of a number than correct is set to false
	    correct = false;
	  }
	}
	if(correct == false) {
	  cout << "Please enter the students id correctly (6 numbers): ";
	}
      }
      
      for(int i = 0; i < 6; i++) {
	//Friend: Nathan Class: C++ programming 6
	//I am using their idea with their permission
	//Their idea was to combine the integer values of each character of the id into a single integer by multiplying each by 10 to the power of it's place value, then adding them
	id += (idText[i] - 48) * pow (10, 5 - i);
	//end of code where idea was used
      }

      if(delStudent(studentList, id) == true) {
	cout << "Deleted student with id " << id << endl;
      } else {
	cout << "Student not found" << endl; 
      }
    }

    if(strcmp(input, "quit") == 0) { //user typed quit command
      running = false;
    }
  }
}
void addStudent(vector<student*>* &studentList, char first[10], char last[10], int id, float gpa) { //adds student to student list
  student* newStudent = new student;
  
  for(int i = 0; i < 10; i++ ) { //sets the first name of the student struct to the passed in value
    newStudent->first[i] = first[i];
  }
  
  for(int i = 0; i < 10; i ++) { //sets the last name of the student struct to the passed in value
    newStudent->last[i] = last[i];
  }
 
  newStudent->id = id;
  newStudent->gpa = gpa;

  studentList->push_back (newStudent); //inserts newStudent after the last element in studentList
  
}

void printStudent(vector<student*>* &studentList) { //prints all students
  for(int i = 0; i < studentList->size(); i++) { //go through each student in student list
    cout << (*studentList)[i]->first << " " << (*studentList)[i]->last << ", ";
    cout << (*studentList)[i]->id << ", ";
    cout << (*studentList)[i]->gpa << endl;
  }
}

bool delStudent(vector<student*>* &studentList, int id) { //deletes a student
  for(int i = 0; i < studentList->size(); i++) { //go through each student in student list until the id matches
    if((*studentList)[i]->id == id) {
      delete[] (*studentList)[i]; //delete the struct itself
      studentList->erase (studentList->begin() + i); //delete the struct pointer from the studentList vector
      return true; //deleted successfully
    } 
  }
  return false; //student not found
}
