#ifndef STUDENT
#define STUDENT

//Student class of linked list. Contains student name, id, and gpa fields, and getters and setters
#include <iostream>

class Student {
 public:
  Student();
  void setName(char* name);
  void setId(int id);
  void setGpa(float gpa);
  char* getName();
  int getId();
  float getGpa();
 private:
  char* name;
  int id;
  float gpa;
};

#endif
