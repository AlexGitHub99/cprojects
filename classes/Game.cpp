#include <iostream>
#include <cstring>
#include "Game.h"

using namespace std;

Game::Game(char* newTitle, int newYear, char* newPublisher, int newRating) {
  strncpy(title, newTitle, 15);
  year = newYear;
  strncpy(publisher, newPublisher, 15);
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

Game::~Game() {
  cout << "Destructor for game class called" << endl;
}
