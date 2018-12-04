#include <cstring>
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
  
  vector<Room*>* rooms = new vector<Room*>();
  
  Room* cell = new Room(strcpy(new char[20], "Cell"));
  rooms->push_back(cell);
  Room* hallway = new Room(strcpy(new char[20], "Hallway"));
  rooms->push_back(hallway);
  Room* library = new Room(strcpy(new char[20], "Library"));
  rooms->push_back(library);
  Room* alchemyRoom = new Room(strcpy(new char[20], "Alchemy Room"));
  rooms->push_back(alchemyRoom);
  Room* diningHall = new Room(strcpy(new char[20], "Dining Hall"));
  rooms->push_back(diningHall);
  Room* kitchen = new Room(strcpy(new char[20], "Kitchen"));
  rooms->push_back(kitchen);
  Room* pantry = new Room(strcpy(new char[20], "Pantry"));
  rooms->push_back(pantry);
  Room* cooridor = new Room(strcpy(new char[20], "Cooridor"));
  rooms->push_back(cooridor);
  Room* throneRoom = new Room(strcpy(new char[20], "Throne Room"));
  rooms->push_back(throneRoom);
  Room* servantsQuarters = new Room(strcpy(new char[20], "Servantd Quarters"));
  rooms->push_back(servantsQuarters);
  Room* guardRoom = new Room(strcpy(new char[20], "Guard Room"));
  rooms->push_back(guardRoom);
  Room* secretTunnel = new Room(strcpy(new char[20], "Secret Tunnel"));
  rooms->push_back(secretTunnel);
  Room* dragonDungeon = new Room(strcpy(new char[20], "Dragon Dungeon"));
  rooms->push_back(dragonDungeon);
  Room* passageway = new Room(strcpy(new char[20], "Passageway"));
  rooms->push_back(passageway);
  Room* outside = new Room(strcpy(new char[20], "Outside"));
  rooms->push_back(outside);

  vector<Item*>* inventory = new vector<Item*>();
  Item* metalKey = new Item(strcpy(new char[15], "Metal Key"));
  Item* goldenKey = new Item(strcpy(new char[15], "Golden Key"));
  Item* woodenKey = new Item(strcpy(new char[15], "Wooden Key"));
  Item* crown = new Item(strcpy(new char[15], "Crown"));
  Item* sword = new Item(strcpy(new char[15], "Sword"));
  Item* book = new Item(strcpy(new char[15], "Book"));
  Item* apple = new Item(strcpy(new char[15], "Apple"));
  Item* bone = new Item(strcpy(new char[15], "Bone"));
  Item* scale = new Item(strcpy(new char[15], "Dragon Scale"));
  
  cell->addItem(metalKey);
  cell->setExit(SOUTH, hallway->getName(), metalKey->getName());
  cell->setDescription(strcpy(new char[200], "You're surrounded by stone brick walls, except for a panel of metal bars and a door with a keyhole."));

  hallway->setExit(EAST, alchemyRoom->getName(), NULL);
  hallway->setExit(SOUTH, diningHall->getName(), NULL);
  hallway->setExit(WEST, library->getName(), NULL);
  hallway->setDescription(strcpy(new char[200], "You step into a long hallway lit by torches. Numerous doors line the walls."));

  alchemyRoom->addItem(goldenKey);
  alchemyRoom->setExit(WEST, hallway->getName(), NULL);
  alchemyRoom->setDescription(strcpy(new char[200], "You enter a room with strange items and vials constaining unknown liquid scattered everywhere. An old wooden workbench is covered with papers displaying obscure diagrams and writings."));
		   
  diningHall->setExit(NORTH, hallway->getName(), NULL);
  diningHall->setExit(SOUTH, kitchen->getName(), NULL);
  diningHall->setDescription(strcpy(new char[200], "You walk into an extravagant dining hall, with a large wooden table running down the center. Servants rush around carrying plates full of food."));

  kitchen->addItem(apple);
  kitchen->setExit(NORTH, diningHall->getName(), NULL);
  kitchen->setExit(EAST, cooridor->getName(), NULL);
  kitchen->setExit(WEST, pantry->getName(), NULL);
  kitchen->setDescription(strcpy(new char[200], "You enter a large, busy kitchen. Food is everywhere, and servants can be seen preparing a variety of meals"));

  pantry->addItem(woodenKey);
  pantry->setExit(EAST, kitchen->getName(), NULL);
  pantry->setDescription(strcpy(new char[200], "You step into a wooded food storage room, with shelves stacking up the ceiling carrying fruits, bread, flour, and any number of jars and bottles."));

  cooridor->setExit(NORTH, servantsQuarters->getName(), NULL);
  cooridor->setExit(EAST, guardRoom->getName(), NULL);
  cooridor->setExit(SOUTH, throneRoom->getName(), goldenKey->getName());
  cooridor->setExit(WEST, kitchen->getName(), NULL);
  cooridor->setDescription(strcpy(new char[200], "A tall, narrow corridor stretches out before you, there are stained glass windows on the sides and ceiling, lighting up the area. Doors lead away in all directions. The largest door is decorated in ornate gold designs, and has a large golden key hole in the center."));

  servantsQuarters->setExit(SOUTH, cooridor->getName(), NULL);
  servantsQuarters->setDescription(strcpy(new char[200], "You step into a drab, dimly lit room, with many beds seperated by wooden barriers. It smells unnapealing. A few servants give you suspicous glances, but leave you alone."));
  
  guardRoom->addItem(sword);
  guardRoom->setExit(WEST, cooridor->getName(), NULL);
  guardRoom->setDescription(strcpy(new char[200], "You warily enter the guard room to find it empty. Armour and weapons are hung on the solid stone walls."));

  throneRoom->addItem(crown);
  throneRoom->setExit(NORTH, cooridor->getName(), goldenKey->getName());
  throneRoom->setDescription(strcpy(new char[200], "You walk into a large room with a high cieling, heavily decorated with gold. An expensive looking throne sits at the center of the back wall. No one can be seen."));
  
  library->addItem(book);
  library->setExit(EAST, hallway->getName(), NULL);
  library->setExit(WEST, secretTunnel->getName(), woodenKey->getName());
  library->setDescription(strcpy(new char[200], "You enter a room filled with shelves and shelves of books, stacking up to the ceiling. At the back of the room, you notice a bookshelf that is pushed in slightly from the others. As you walk up for a closer look, you notice a small wooden keyhole on the right side."));
  
  secretTunnel->setExit(EAST, library->getName(), woodenKey->getName());
  secretTunnel->setExit(WEST, dragonDungeon->getName(), sword->getName());
  secretTunnel->setDescription(strcpy(new char[200], "As you slide the key into the bookshelf, it swings open, revealing a dark, stone tunnel behind it. It smells musty, and you can hear water dripping down the tunnel."));
  
  dragonDungeon->addItem(bone);
  dragonDungeon->addItem(scale);
  dragonDungeon->setExit(EAST, library->getName(), NULL);
  dragonDungeon->setExit(NORTH, passageway->getName(), NULL);
  char dragonDungeonDescription2[] = "You walk past the slayed dragon into a huge cavern with moss climbing up its walls. The'res a light somewhere in the distance.";
  dragonDungeon->setDescription(strcpy(new char[200], "After stabbing the dragon with your sword, it fell to the ground, dead. You walk past the slayed dragon into a huge cavern with moss climbing up its walls. There's a light somewhere in the distance."));

  passageway->setExit(SOUTH, dragonDungeon->getName(), NULL);
  passageway->setExit(NORTH, outside->getName(), crown->getName());
  passageway->setDescription(strcpy(new char[200], "After traveling toward the light, you enter a long passageway carved into the stone. At the end you can see an exit leading outside, but there are four guards visisble on either side."));

  outside->setDescription(strcpy(new char[200], "When the guards see your crown, they let you pass immediately, bowing respectfully. You look out onto an open mountainous landscape and a clear blue sky."));

  cout << "Welcome to Zuul: escape the castle!" << endl;
  cout << "Commands:" << endl;
  cout << "observe -- view items in the room" << endl;
  cout << "go <n/e/s/w> -- go a direction" << endl;
  cout << "pickup <itemname> -- pickup an item" << endl;
  cout << "drop <itemname> -- drop an item into the room your in" << endl;
  cout << "inv -- view your inventory" << endl;
  
  Room* currentRoom;
  currentRoom = cell;

  cout << "Room: " << cell->getName() << endl;
  currentRoom->printDescription();
  
  char input[21];
  cin.getline(input, 21);

  bool valid = false;
  if(strcmp(input, "observe") == 0) {
    vector<Item*>* items = currentRoom->getItems();
    for(int i = 0; i < items->size(); i++) {
      cout << (*items)[i]->getName() << " ";
    }
    cout << endl;
    valid = true;
  } else if(strcmp(input, "inv") == 0) {
    for(int i = 0; i < inventory->size(); i ++) {
      cout << (*inventory)[i]->getName();
    }
    cout << endl;
    valid = true;
  } else {

    char first[10];
    bool space;
    int i = 0;
    while(space == false) {
      if(input[i] == ' ') {
	space = true;
      }
      first[i] = input[i];
      i++;
    }

    char second[10];
    int j = 0;
    for(i+1; i < strlen(input)-i; i++) {
      second[j] = input[i];
      j++;
    }
    
    if(strcmp(first, "go") == 0) {
      if(strcmp(second, "n") == 0) {
	for(int i = 0; i < rooms->size(); i++) {
	  if(strcmp(currentRoom->getExit(NORTH), (*rooms)[i]->getName()) == 0) {
	    if(currentRoom->getKey(NORTH) == NULL) {   
	      currentRoom = (*rooms)[i];
	    } else {
	      bool unlocked = false;
	      for(int j = 0; j < inventory->size(); j++) {
		if(strcmp((*inventory)[j]->getName(), currentRoom->getKey(NORTH)) == 0) {
		  currentRoom = (*rooms)[i];
		  unlocked = true;
		}
	      }
	      if(unlocked = false) {
		
	      }
	    }   
	  }
	} else if(strcmp(second, "e") == 0) {

	}
      }
    }
  }
    
