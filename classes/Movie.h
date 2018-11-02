#ifndef MOVIE
#define MOVIE

#include <iostream>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie(char* newTitle, int newYear, char* newDirector, int newRating);
  virtual int getType();
  virtual char* getTitle();
  virtual int getYear();
  virtual char* getDirector();
 private:
  char* title;
  int year;
  char* director;
  int rating;
};

#endif
