#include "Student.h"

using namespace std;

Student::Student(char* newFirst, char* newLast, int newId, float newGpa) {
  strcpy(first, newFirst)
  strcp(last, newLast);
  id = newId;
  gpa = newGpa;
}

char* Student::getFirst() {
  return first;
}

char* Student::getLast() {
  return last;
}

int Student::getId() {
  return id;
}

float Student::getGpa() {
  return gpa;
}


