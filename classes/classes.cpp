#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

int main() {
  Media* media;
  char newTitle[15];
  char newPublisher[15];
  Movie* movie = new Movie(newTitle, 5, newPublisher, 4);
  int num = movie->getRating();
  cout << num;
  media = movie;
  cout << media->getRating();
}
