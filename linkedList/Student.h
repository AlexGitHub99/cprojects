//Student class of linked list. Cohtains student name, grade, and gpa fields, and getters and setters
#include <iostream>

class Student {
 public:
  void setName(char* name);
  void setGrade(int grade);
  void setGpa(float gpa);
  char* getName();
  int getGrade();
  void getGpa();
 private:
  char* name;
  int grade;
  float gpa;
};
