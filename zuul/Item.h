#ifndef ITEM
#define ITEM

#include <iostream>

using namespace std;

class Item {
 public:
  Item(char* newName);
  char* getName();
 private:
  char* name;
};

#endif
