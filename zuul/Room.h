#ifndef ROOM
#define ROOM

#include <iostream>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room {
 public:
  Room(char* newDescription, char* newName);
  char* getDescription();
  char* getName();
  vector<Item*>* getItems();
  char* getExit(int direction);
  char* getKey(int direction);
  Item* getItem(char* name);
  void addItem(Item* item);
  void setExit(int direction, char* name, char* key);
  void printItems();
 private:
  vector<Item*>* items = new vector<Item*>();
  map<int, char*> exits;
  map<int, char*> exitKeys;
  char* description;
  char* name;
};

#endif
