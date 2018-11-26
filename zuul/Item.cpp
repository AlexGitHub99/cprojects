#include <iostream>
#include <cstring>
#include "Item.h"

using namespace std;

Item::Item(char newName[]) {
  strcpy(newName, name);
}

char* Item::getName() {
  return name;
}
