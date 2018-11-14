#include <iostream>
#include <cstring>
#include "Media.h"
#include "Movie.h"

using namespace std;

Movie::Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int newRating) {
  strncpy(title, newTitle, 15);
  year = newYear;
  strncpy(director, newDirector, 15);
  duration = newDuration;
  rating = newRating;
}

int Movie::getType() {
  return 1; //1 for Movie
}

char* Movie::getTitle() {
  return title;
}

int Movie::getYear() {
  return year;
}

int Movie::getDuration() {
  return duration;
}

char* Movie::getDirector() {
  return director;
}

int Movie::getRating() {
  return rating;
}

Movie::~Movie() {
  cout << "Destructor called for movie class";
}
