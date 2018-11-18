#include <iostream>

class Room {
 public:
  Room(char* newDescription, int newId);
  char* getDescription();
  vector<Item*> getItems();
  void addItem(Item*)
  int getId();
 private:
  vector<Item*> items;
  char* description;
  int id;
};
