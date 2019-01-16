/***
Author: Alex King
Last modified: 1/15/19
This program stores a list of students using a linked list of student classes. Each class contains a first name, last name, id, and gpa.
Users can type in command add, print, delete, avggpa, and quit.
 ***/
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <ios>
#include "Node.h"

using namespace std;

void addStudent(Node* next, char first[11], char last[11], int id, float gpa);
void printStudent(Node* &head, Node* next);
bool delStudent(Node* next, int id);
void avg(Node* &head, Node* next, float sum, int num);
int main() {
  //I got this code from stack overflow user:Melebius
  //http://stackoverflow.com/questions/14369673/round-double-to-3-points-decimal
  cout.setf(ios::fixed); //makes the significant digit precision for floats be followed exactly, inserting trailing zeroes if needed
  cout.precision(2); //sets the significant digits for floats to 2
  //End of used code
  
  Node* head = new Node(NULL); //creates head node of linked list
  
  cout << "Welcome to Student List! Commands:" << endl << "add - add a student" << endl << "print - prints all students" << endl << "delete - delete a student" << endl << "avggpa - prints out an avg of all students gpa" << endl << "quit - quit the program" << endl;
  
  bool running = true;
  
  while(running == true) { //main loop
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

      
      addStudent(head, first, last, id, gpa);
      cout << "Added " << first << " " << last << " with id " << id << " and gpa " << gpa << endl;
    }
    
    if(strcmp(input, "print") == 0) { //user typed print command
      printStudent(head, head);
    }
    if(strcmp(input, "avggpa") == 0) { //user types avg command
      avg(head, head, 0, 0);
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

      if(delStudent(head, id) == true) {
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
void addStudent(Node* next, char first[10], char last[10], int id, float gpa) { //adds student to student list
  if(next->getNext() == NULL) {

    Student* newStudent = new Student(first, last, id, gpa);
    
    Node* newNode = new Node(newStudent);
    next->setNext(newNode);
  } else {
    addStudent(next->getNext(), first, last, id, gpa);
  }
  
}

void printStudent(Node* &head, Node* next) { //prints all students
  if(next == head) {
    cout << "Students:" << endl;
  }
  if(next->getNext() != NULL) {
    cout << "First Name: " << next->getNext()->getStudent()->getFirst() << endl;
    cout << "Last Name: " << next->getNext()->getStudent()->getLast() << endl;
    cout << "Student ID: " << next->getNext()->getStudent()->getId() << endl;
    cout << "GPA: " << next->getNext()->getStudent()->getGpa() << endl;
    cout << "----------------------------------" << endl;
    printStudent(head, next->getNext());
  }
}

bool delStudent(Node* next, int id) { //deletes a student
  if(next != NULL) {
    if(next->getNext() != NULL) {
      bool success = false;
      if(next->getNext()->getStudent()->getId() == id) { //test the next node's student for a matching id
	Node* tempNext = next->getNext(); //create a temporary pointer to the next node so it can be deleted later 
	next->setNext(next->getNext()->getNext()); //set the current node's next node to the next node's next node (two nodes down)
	delete tempNext; //delete the former next node
	success = true;
      }
      if(delStudent(next->getNext(), id) == true or success == true) { //runs the function again. If it returns true (one of the successive recursions
	//found the student and deleted it successfully) or success is true (the current recursion found the student and deleted it sucessfuly) then return true.
	return true;
      }
    }
  }
  //either the current node is NULL or the next node is NULL, end of the list has been reached, so return false (no student found and deleted this recursion);
  return false;
}

void avg(Node* &head, Node* next, float sum, int num) {
  if(next == head) {
    cout << "Average gpa of all students:" << endl;
  }
  if(next->getNext() != NULL) {
    sum += next->getNext()->getStudent()->getGpa(); //add next students gpa to total
    num += 1; //add 1 to the student count
    avg(head, next->getNext(), sum, num);
  } else {
    if(num == 0) { //no students in list
      cout << "No students in list";
	} else {
    cout << sum / num << endl; // print out sum of gpas divided by the number of students to find the average
    }
  }
}
