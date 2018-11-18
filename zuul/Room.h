#ifndef ROOM
#define ROOM

#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class Room {
 public:
  Room(char* newDescription, int newId);
  char* getDescription();
  vector<Item*>* getItems();
  void addItem(Item*);
  int getId();
 private:
  vector<Item*>* items = new vector<Item*>();
  char* description;
  int id;
};

#endif
