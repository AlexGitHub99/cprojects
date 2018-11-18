#include <iostream>
#include "Item.h"

using namespace std;

Item::Item(char* newName, int newId) {
  name = newName;
  id = newId;
}

char* Item::getName() {
  return name;
}

int Item::getId() {
  return id;
}
