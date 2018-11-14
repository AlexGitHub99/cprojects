#include <iostream>
#include <cstring>
#include "Music.h"

using namespace std;

Music::Music(char* newTitle, char* newArtist, int newYear, int newDuration, char* newPublisher) {
  strncpy(title, newTitle, 15);
  strncpy(artist, newArtist, 15);
  year = newYear;
  duration = newDuration;
  strncpy(publisher, newPublisher, 15);
}

int Music::getType() {
  return 3; //3 for music
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

Music::~Music() {
  cout << "Destructor called for music class" << endl;
}





