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
  virtual int getRating();
  virtual ~Movie();
 private:
  char title[15];
  int year;
  char director[15];
  int rating;
  int duration;
};

#endif
