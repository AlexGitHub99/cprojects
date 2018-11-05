#include <iostream>
#include "Music.h"

using namespace std;

Music::Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher) {
  title = newTitle;
  artist = newArtist;
  year = newYear;
  duration = newDuration;
  publisher = newPublisher;
}

int Music::getType() {
  return 3;
}

char* Music::getTitle() {
  return title;
}

char* Music::getArtist() {
  return artist;
}

int Music::getYear() {
  return year;
}

int Music::getDuration() {
  return duration;
}

char* Music::getPublisher() {
  return publisher;
}







