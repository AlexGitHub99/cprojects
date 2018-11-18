#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

Room::Room(char* newDescription, int newId) {
  description = newDescription;
  id = newId;
}

char* Room::getDescription() {
  return description;
}

vector<Item*>* Room::getItems() {
  return items;
}

void Room::addItem(Item* item) {
  items->push_back(item);
}

int Room::getId() {
  return id;
}
