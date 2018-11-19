#include <iostream>
#include <vector>
#include "Room.h"
#include "Item.h"

using namespace std;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;

int main() {
  Room* room = new Room("Room", "Bathroom", 100);
  room->addItem(new Item("Apple", 2));
  vector<Item*>* items = room->getItems();
  for(int i = 0; i < items->size(); i++) {
    cout << (*items)[i]->getName() << endl;
  }

  Room* room2 = new Room("Second room", "Lunch room", 9);
  
  room->addExit(NORTH, 9);
  cout << (room->getExit(NORTH)) << endl;;
}
