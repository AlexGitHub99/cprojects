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
  Room* room = new Room("Room");
  room->addItem(new Item("Apple"));
  vector<Item*>* items = room->getItems();
  for(int i = 0; i < items->size(); i++) {
    cout << (*items)[i]->getName() << endl;
  }

  Room* room2 = new Room("Second room");
    
  room->setExit(NORTH, "Room", "");
  cout << (room->getExit(NORTH)) << endl;
  cout << (room->getKey(NORTH)) << endl;
  
  vector<Room*>* rooms = new vector<Room*>();

  Room* cell = new Room("Cell");
  Room* hallway = new Room("Hallway");
  Room* library = new Room("Libary");
  Room* alchemyRoom = new Room("Alchemy room");
  Room* diningHall = new Room("Dining Hall");
  Room* kitchen = new Room("Kitchen");
  Room* pantry = new Room("Pantry");
  Room* cooridor = new Room("Cooridor");
  Room* throneRoom = new Room("Throne Room");
  Room* servantsQuarters = new Room("Servants Quarters");
  Room* guardRoom = new Room("Guard Room");
  Room* secretTunnel = new Room("Secret tunnel");
  Room* dragonDungeon = new Room("Dragon Dungeon");
  Room* passageway = new Room("Passageway");
  Room* outside = new Room("Outside");
  
  hallway->setDescription("You step into a long hallway lit by torches. Numerous doors line the walls.");
  cell->setDescription("You're surrounded by stone brick walls, except for a panel of metal bars and a door with a keyhole.");
			      
}
