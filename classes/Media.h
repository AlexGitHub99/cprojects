#ifndef MEDIA
#define MEDIA

#include <iostream>

using namespace std;

class Media {
 public:
  Media();
  virtual int getType();
  virtual char* getTitle();
  virtual int getYear();
  virtual char* getPublisher();
  virtual int getRating();
  virtual char* getDirector();
  virtual char* getArtist();
  virtual int getDuration(); 
 private:
  char* title;
  int year;
  char* publisher;
  int rating;
  char* director;
  char* artist;
  int duration;
};

#endif
