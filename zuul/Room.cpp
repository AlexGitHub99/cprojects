#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

Room::Room(char* newDescription, int newId) {
  description = newDescription;
  id = newId;
}

char* getDescription() {
  return description;
}

vector<item*> getItems() {
  return items;
}

void addItem(Item* item) {
  items.push_back(item);
}

int getID() {
  return id;
}
