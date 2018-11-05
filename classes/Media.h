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
 private:
  char* title;
  int year;
};

#endif
