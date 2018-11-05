#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

int main() {
  Media* media;
  char newTitle[15] = "Applebee";
  char newDirector[15] = "Bob";
  Movie* movie = new Movie(newTitle, 5, newDirector, 4);
  cout << movie->getDirector();
  media = movie;
  Movie* movie2 = dynamic_cast<Movie*>(media);
  cout << movie2->getDirector();
}
