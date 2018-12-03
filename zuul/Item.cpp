#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item(char* newName) {
  strcpy(name, newName);
}

char* Item::getName() {
  return name;
}
