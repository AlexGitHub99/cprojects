#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

Movie::Movie() {
  cout << "test";
}

int Movie::getType() {
  return 1; //1 for Movie
}
