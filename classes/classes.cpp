#include <iostream>
#include <vector>
#include "Media.h"
#include "Movie.h"
#include "Game.h"
#include "Music.h"

using namespace std;

void addMovie(vector<Media*>* files, char* title, char* director, int year, int duration, int rating);
void addGame(vector<Media*>* files, char* title, int year, char* publisher, int rating);
void addMusic(vector<Media*>* files, char* title, char* artist, int year, int duration, char* publisher);
	     
int main() {
  Media* media;
  char newTitle[15] = "Applebee";
  char newDirector[15] = "Bob";
  Movie* movie = new Movie(newTitle, newDirector, 5, 1000, 4);
  cout << movie->getDirector();
  media = movie;
  Movie* movie2 = dynamic_cast<Movie*>(media);
  cout << movie2->getDirector();

  vector<Media*>* files = new vector<Media*>();
  addMovie(files, "Banana", "Joseph", 1990, 7200, 5);
}

void addMovie(vector<Media*>* files, char* title, char* director, int year, int duration, int rating) {
  Movie* movie = new Movie(title, director, year, duration, rating);
  files->push_back(movie);
}

void addGame(vector<Media*>* files, char* title, int year, char* publisher, int rating) {
  Game* game = new Game(title, year, publisher, rating);
  files->push_back(game);
}

void addMusic(vector<Media*>* files, char* title, char* artist, int year, int duration, char* publisher) {
  Music* music = new Music(title, artist, year, duration, publisher);
  files->push_back(music);
}
