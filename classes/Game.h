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
  virtual char* getPublisher();
  virtual int getRating();
  
 private:
  char* title;
  int year;
  char* publisher;
  int rating;
};

#endif
