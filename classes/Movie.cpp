#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

Movie::Movie(char* newTitle, int newYear, char* newPublisher, int newRating) {
  title = newTitle;
  year = newYear;
  publisher = newPublisher;
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

char* Movie::getPublisher() {
  return publisher;
}

int Movie::getRating() {
  return rating;
}
