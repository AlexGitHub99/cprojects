#ifndef MEDIA
#define MEDIA

#include <iostream>

using namespace std;

class Media {
 public:
  Media();
  int getType();
  char* getTitle();
  int getYear();
  char* getPublisher();
  int getRating();
};

#endif
