#include <iostream>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

int main() {
  Room* room = new Room("Room", 100);
  room->addItem(new Item("Apple", 2));
  vector<Item*>* items = room->getItems();
  for(int i = 0; i < items->size(); i++) {
    cout << (*items)[i]->getName() << endl;
  }
}
