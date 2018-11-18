#ifndef ITEM
#define ITEM

#include <iostream>

using namespace std;

class Item {
 public:
  Item(char* newName, int newId);
  char* getName();
  int getId();
 private:
  char* name;
  int id;
};

#endif
