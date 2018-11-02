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

char* Media::getPublisher() {
  return publisher;
}

int Media::getRating() {
  return rating;
}

char* Media::getDirector() {
  return director;
}

char* Media::getArtist() {
  return artist;
}

int Media::getDuration() {
  return duration;
}
