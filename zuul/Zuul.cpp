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
  Room* room = new Room("Room", "Bathroom");
  room->addItem(new Item("Apple"));
  vector<Item*>* items = room->getItems();
  for(int i = 0; i < items->size(); i++) {
    cout << (*items)[i]->getName() << endl;
  }

  Room* room2 = new Room("Second room", "Lunch room");
    
  room->setExit(NORTH, "Room", "");
  cout << (room->getExit(NORTH)) << endl;
  cout << (room->getKey(NORTH)) << endl;
  
  vector<Room*>* rooms = new vector<Room*>();
  
}
