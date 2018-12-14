/*
Nathan Taylor
Header File for Node Class
HAVE FUN!
*/

#include <cstring>
#include <cstdlib>
#include <iostream>
#include "student.h"

using namespace std;

class Node
{
 public:
  //class init
  Node();//sets data and next to null
  
  //destructor
  ~Node();//deletes student
  
  //function init
  setStudent(Student* nstudent);
  Student* getStudent();
  setNext(Node* nnode);
  Node* getNext();
  
  //variable init
  Node* next;
  Student* data;
};
