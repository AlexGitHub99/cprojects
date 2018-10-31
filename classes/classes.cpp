#include <iostream>
#include "Media.h"
#include "Movie.h"

using namespace std;

int main() {
  Media* media = new Media();
  Movie* movie = new Movie();
  int num = movie->getType();
  cout << num;
}
