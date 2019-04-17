#include "student.h"
#include <cstring>
using namespace std;

Student::Student(char newFirst[10], char newLast[10], int newId, float newGpa) {
  strcpy(first, newFirst);
  strcpy(last, newLast);
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


