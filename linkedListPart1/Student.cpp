#include "student.h"
#include <iostream>
#include <cstring>

Student::Student() {
}

void Student::setName(char* newName) {
  strcpy(name, newName);
}

void Student::setId(int newId) {
  id = newId;
}

void Student::setGpa(float newGpa) {
  gpa = newGpa;
}

char* Student::getName() {
  return name;
}

int Student::getId() {
  return id;
}

float Student::getGpa() {
  return gpa;
}
