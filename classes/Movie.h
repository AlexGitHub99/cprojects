#include <iostream>
#include "Media.h"

using namespace std;

class Movie : public Media {
 public:
  Movie();
  int getType();
};
