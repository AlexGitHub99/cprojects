#include <iostream>
#include <vector>
#include "Room.h"

using namespace std;

Room::Room(char* newDescription, char* newName, int newId) {
  description = newDescription;
  name = newName;
  id = newId;
}

char* Room::getDescription() {
  return description;
}

char* Room::getName() {
  return name;
}

vector<Item*>* Room::getItems() {
  return items;
}

int Room::getExit(int direction) {
  return exits[direction];
  }

void Room::addItem(Item* item) {
  items->push_back(item);
}

void Room::addExit(int direction, int id) {
  exits[direction] = id;
}

int Room::getId() {
  return id;
}
