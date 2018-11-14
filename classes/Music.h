#ifndef MUSIC
#define MUSIC

#include <iostream>
#include "Media.h"

using namespace std;

class Music : public Media {
 public:
  Music(char* newTitle, char* artist, int year, int duration, char* publisher);
  virtual int getType();
  virtual char* getTitle();
  char* getArtist();
  virtual int getYear();
  int getDuration();
  char* getPublisher();
  virtual ~Music();
 private:
  char title[15];
  char artist[15];
  int year;
  int duration;
  char publisher[15];
};

#endif
