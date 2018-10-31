#ifndef MOVIE
#define MOVIE

#include <iostream>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie();
  int getType();
  char* getTitle();
  int getYear();
  char* getPublisher();
 private:
  char* title;
  int year;
  char* publisher;
  int rating;
};

#endif
