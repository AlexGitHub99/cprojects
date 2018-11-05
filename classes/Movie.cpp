#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

Movie::Movie(char* newTitle, int newYear, char* newDirector, int newRating) {
  title = newTitle;
  year = newYear;
  director = newDirector;
  rating = newRating;
}

int Movie::getType() {
  return 2; //1 for Movie
}

char* Movie::getTitle() {
  return title;
}

int Movie::getYear() {
  return year;
}

char* Movie::getDirector() {
  return director;
}
