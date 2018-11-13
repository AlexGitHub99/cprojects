#include <iostream>
#include "Game.h"

using namespace std;

Game::Game(char* newTitle, int newYear, char* newPublisher, int newRating) {
  title = newTitle;
  year = newYear;
  publisher = newPublisher;
  rating = newRating;
}

int Game::getType() {
  return 2; //2 for game
}

char* Game::getTitle() {
  return title;
}

int Game::getYear() {
  return year;
}

char* Game::getPublisher() {
  return publisher;
}

int Game::getRating() {
  return rating;
}
