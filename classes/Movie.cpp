#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

Movie::Movie(char* newTitle, char* newDirector, int newYear, int newDuration, int newRating) {
  title = newTitle;
  year = newYear;
  director = newDirector;
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
