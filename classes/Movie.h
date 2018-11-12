#ifndef MOVIE
#define MOVIE

#include <iostream>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int newRating);
  virtual int getType();
  virtual char* getTitle();
  virtual int getYear();
  virtual char* getDirector();
  virtual int getDuration();
 private:
  char* title;
  int year;
  char* director;
  int rating;
  int duration;
};

#endif
