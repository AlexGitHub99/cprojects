#ifndef MUSIC
#define MUSIC

#include <iostream>
#include "Media.h"

using namespace std;

class Music : public Media {
 public:
  Music(char* newTitle, char* artist, int year, int duration, char* publisher);
  int getType();
  char* getTitle();
  char* getArtist();
  int getYear();
  int getDuration();
  char* getPublisher();
 private:
  char* title;
  char* artist;
  int year;
  int duration;
  char* publisher;
};

#endif
