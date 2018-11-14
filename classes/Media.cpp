#include <iostream>
#include "Media.h"

using namespace std;

Media::Media() {
};

int Media::getType() {
  return 0;
}

char* Media::getTitle() {
  return title;
}

int Media::getYear() {
  return year;
}

Media::~Media() {
  cout << "Destructor called for media class" << endl;
}
