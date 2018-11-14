#ifndef GAME
#define GAME

#include <iostream>
#include "Media.h"

using namespace std;

class Game : public Media {
 public:
  Game(char* newTitle, int newYear, char* newPublisher, int newRating);
  virtual int getType();
  virtual char* getTitle();
  virtual int getYear();
  char* getPublisher();
  int getRating();
  virtual ~Game();
 private:
  char title[15];
  int year;
  char publisher[15];
  int rating;
};

#endif
