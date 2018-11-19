#ifndef ROOM
#define ROOM

#include <iostream>
#include <vector>
#include <map>
#include "Item.h"

using namespace std;

class Room {
 public:
  Room(char* newDescription, char* newName, int newId);
  char* getDescription();
  char* getName();
  vector<Item*>* getItems();
  int getExit(int direction);
  void addItem(Item*);
  void addExit(int direction, int id); 
  int getId();
 private:
  vector<Item*>* items = new vector<Item*>();
  map<int, int> exits;
  char* description;
  char* name;
  int id;
};

#endif
