//Student class of linked list. Cohtains student name, id, and gpa fields, and getters and setters
#include <iostream>

class Student {
 public:
  void setName(char* name);
  void setid(int id);
  void setGpa(float gpa);
  char* getName();
  int getGrade();
  void getGpa();
 private:
  char* name;
  int id;
  float gpa;
};
