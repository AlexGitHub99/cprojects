#include <iostream>
#include <vector>
#include "Room.h"
#include <cstring>

using namespace std;

Room::Room(char* newName) {
  name = newName;
}

void Room::printDescription() {
  cout << description;
}

char* Room::getName() {
  return name;
}

vector<Item*>* Room::getItems() {
  return items;
}

char* Room::getExit(int direction) {
  return exits[direction];  
}

char* Room::getKey(int direction) {
  return exitKeys[direction];
}

Item* Room::getItem(char* itemName) {
  for(int i = 0; i < items->size(); i++) {
    if(strcmp((*items)[i]->getName(), itemName) == 0) {
      return (*items)[i];
    }
  }
}

void Room::addItem(Item* item) {
  items->push_back(item);
}

void Room::setExit(int direction, char* name, char* key) {
  strcpy(exits[direction], name);
  strcpy(exitKeys[direction], key);
}

void Room::setDescription(char* newDescription) {
  strcpy(description, newDescription);
}
