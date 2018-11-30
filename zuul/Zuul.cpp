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
  char cellName[] = "Cell";
  Room* cell = new Room(cellName);
  rooms->push_back(cell);
  char hallwayName[] = "Hallway";
  Room* hallway = new Room(hallwayName);
  rooms->push_back(hallway);
  char libraryName[] = "Library";
  Room* library = new Room(libraryName);
  rooms->push_back(library);
  char alchemyRoomName[] = "Alechemy Room";
  Room* alchemyRoom = new Room(alchemyRoomName);
  rooms->push_back(alchemyRoom);
  char diningHallName[] = "Dining Hall";
  Room* diningHall = new Room(diningHallName);
  rooms->push_back(diningHall);
  char kitchenName[] = "Kitchen";
  Room* kitchen = new Room(kitchenName);
  rooms->push_back(kitchen);
  char pantryName[] = "Pantry";
  Room* pantry = new Room(pantryName);
  rooms->push_back(pantry);
  char cooridorName[] = "Cooridor";
  Room* cooridor = new Room(cooridorName);
  rooms->push_back(cooridor);
  char throneRoomName[] = "Throne Room";
  Room* throneRoom = new Room(throneRoomName);
  rooms->push_back(throneRoom);
  char servantsQuartersName[] = "Servants Quarters";
  Room* servantsQuarters = new Room(servantsQuartersName);
  rooms->push_back(servantsQuarters);
  char guardRoomName[] = "Guard Room";
  Room* guardRoom = new Room(guardRoomName);
  rooms->push_back(guardRoom);
  char secretTunnelName[] = "Secret Tunnel";
  Room* secretTunnel = new Room(secretTunnelName);
  rooms->push_back(secretTunnel);
  char dragonDungeonName[] = "Dragon Dungeon";
  Room* dragonDungeon = new Room(dragonDungeonName);
  rooms->push_back(dragonDungeon);
  char passagewayName[] = "Passageway";
  Room* passageway = new Room(passagewayName);
  rooms->push_back(passageway);
  char outsideName[] = "Outside";
  Room* outside = new Room(outsideName);
  rooms->push_back(outside);

  vector<Item*>* inventory = new vector<Item*>();
  char metalKeyName[] = "Metal Key";
  char goldenKeyName[] = "Golden Key";
  char woodenKeyName[] = "Wooden Key";
  char crownName[] = "Crown";
  char swordName[] = "Sword";
  char bookName[] = "Book";
  char appleName[] = "Apple";
  char boneName[] = "Bone";
  char scaleName[] = "Dragon scale";
  
  cell->addItem(new Item(metalKeyName));
  cell->setExit(SOUTH, hallwayName, metalKeyName);
  char cellDescription[] = "You're surrounded by stone brick walls, except for a panel of metal bars and a door with a keyhole.";
  cell->setDescription(cellDescription);

  hallway->setExit(EAST, alchemyRoomName, NULL);
  hallway->setExit(SOUTH, diningHallName, NULL);
  hallway->setExit(WEST, libraryName, NULL);
  char hallwayDescription[] = "You step into a long hallway lit by torches. Numerous doors line the walls.";
  hallway->setDescription(hallwayDescription);

  alchemyRoom->addItem(new Item(goldenKeyName));
  alchemyRoom->setExit(WEST, hallwayName, NULL);
  char alchemyRoomDescription[] = "You enter a room with strange items and vials constaining unknown liquid scattered everywhere. An old wooden workbench is covered with papers displaying obscure diagrams and writings.";
  alchemyRoom->setDescription(alchemyRoomDescription);
		   
  diningHall->setExit(NORTH, hallwayName, NULL);
  diningHall->setExit(SOUTH, kitchenName, NULL);
  char diningHallDescription[] = "You walk into an extravagant dining hall, with a large wooden table running down the center. Servants rush around carrying plates full of food.";
  diningHall->setDescription(diningHallDescription);

  kitchen->addItem(new Item(appleName));
  kitchen->setExit(NORTH, diningHallName, NULL);
  kitchen->setExit(EAST, cooridorName, NULL);
  kitchen->setExit(WEST, pantryName, NULL);
  char kitchenDescription[] = "You enter a large, busy kitchen. Food is everywhere, and servants can be seen preparing a variety of meals";
  kitchen->setDescription(kitchenDescription);

  pantry->addItem(new Item(woodenKeyName));
  pantry->setExit(EAST, kitchenName, NULL);
  char pantryDescription[] = "You step into a wooded food storage room, with shelves stacking up the ceiling carrying fruits, bread, flour, and any number of jars and bottles.";
  pantry->setDescription(pantryDescription);

  cooridor->setExit(NORTH, servantsQuartersName, NULL);
  cooridor->setExit(EAST, guardRoomName, NULL);
  cooridor->setExit(SOUTH, throneRoomName, goldenKeyName);
  cooridor->setExit(WEST, kitchenName, NULL);
  char cooridorDescription[] = "A tall, narrow corridor stretches out before you, there are stained glass windows on the sides and ceiling, lighting up the area. Doors lead away in all directions. The largest door is decorated in ornate gold designs, and has a large golden key hole in the center.";
  cooridor->setDescription(cooridorDescription);

  servantsQuarters->setExit(SOUTH, cooridorName, NULL);
  char servantsQuartersDescription[] = "You step into a drab, dimly lit room, with many beds seperated by wooden barriers. It smells unnapealing. A few servants give you suspicous glances, but leave you alone.";
  servantsQuarters->setDescription(servantsQuartersDescription);
  
  guardRoom->addItem(new Item(swordName));
  guardRoom->setExit(WEST, cooridorName, NULL);
  char guardRoomDescription[] = "You warily enter the guard room to find it empty. Armour and weapons are hung on the solid stone walls.";
  guardRoom->setDescription(guardRoomDescription);

  throneRoom->addItem(new Item(crownName));
  throneRoom->setExit(NORTH, cooridorName, goldenKeyName);
  char throneRoomDescription[] = "You walk into a large room with a high cieling, heavily decorated with gold. An expensive looking throne sits at the center of the back wall. No one can be seen.";
  throneRoom->setDescription(throneRoomDescription);
  
  library->addItem(new Item(bookName));
  library->setExit(EAST, hallwayName, NULL);
  library->setExit(WEST, secretTunnelName, woodenKeyName);
  char libraryDescription[] = "You enter a room filled with shelves and shelves of books, stacking up to the ceiling. At the back of the room, you notice a bookshelf that is pushed in slightly from the others. As you walk up for a closer look, you notice a small wooden keyhole on the right side.";
  library->setDescription(libraryDescription);
  
  secretTunnel->setExit(EAST, libraryName, woodenKeyName);
  secretTunnel->setExit(WEST, dragonDungeonName, swordName);
  char secretTunnelDescription[] = "As you slide the key into the bookshelf, it swings open, revealing a dark, stone tunnel behind it. It smells musty, and you can hear water dripping down the tunnel.";
  secretTunnel->setDescription(secretTunnelDescription);
  
  dragonDungeon->addItem(new Item(boneName));
  dragonDungeon->addItem(new Item(scaleName));
  dragonDungeon->setExit(EAST, libraryName, NULL);
  dragonDungeon->setExit(NORTH, passagewayName, NULL);
  char dragonDungeonDescription[] = "After stabbing the dragon with your sword, it fell to the ground, dead. You walk past the slayed dragon into a huge cavern with moss climbing up its walls. There's a light somewhere in the distance.";
  char dragonDungeonDescription2[] = "You walk past the slayed dragon into a huge cavern with moss climbing up its walls. The'res a light somewhere in the distance.";
  dragonDungeon->setDescription(dragonDungeonDescription);

  passageway->setExit(SOUTH, dragonDungeonName, NULL);
  passageway->setExit(NORTH, outsideName, crownName);
  char passagewayDescription[] = "After traveling toward the light, you enter a long passageway carved into the stone. At the end you can see an exit leading outside, but there are four guards visisble on either side.";
  passageway->setDescription(passagewayDescription);

  outside->setExit(SOUTH, passagewayName, outsideName);
  char outsideDescription[] = "When the guards see your crown, they let you pass immediately, bowing respectly. You look out onto an open mountainous landscape and a clear blue sky.";
  outside->setDescription(outsideDescription);

  cout << "Welcome to Zuul: escape the castle!";
}
