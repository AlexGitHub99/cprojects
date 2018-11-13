#include <iostream>
#include <cstring>
#include <vector>
#include "Media.h"
#include "Movie.h"
#include "Game.h"
#include "Music.h"

using namespace std;

void addMovie(vector<Media*>* files, char* title, char* director, int year, int duration, int rating);
void addGame(vector<Media*>* files, char* title, int year, char* publisher, int rating);
void addMusic(vector<Media*>* files, char* title, char* artist, int year, int duration, char* publisher);
vector<int> searchTitle(vector<Media*>* files, char* title);
vector<int> searchYear(vector<Media*>* files, int year);
void print(Media*);

int main() {
  vector<Media*>* files = new vector<Media*>();
  addMovie(files, "Banana", "Joseph", 1990, 7200, 9);
  addMusic(files, "Sicko mode", "Bob", 1990, 120, "kaled");
  addGame(files, "Mario", 1990, "Nintendo", 9);
  vector<int> results = searchYear(files, 1990);
  vector<int> results2 = searchTitle(files, "Banana");
  
  for(int i = 0; i < results.size(); i++) {
    print((*files)[results[i]]);
  }
  
  delete[] (*files)[2];
  files->erase(files->begin() + 1);
  
  for(int i = 0; i < results.size(); i++) {
    print((*files)[results[i]]);
  }
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

vector<int> searchTitle(vector<Media*>* files, char* title) {
  vector<int> results;
  for(int i = 0; i < files->size(); i++) {
    if(strcmp((*files)[i]->getTitle(), title) == 0) {
      results.push_back(i);
    }
  }
  return results;
}
 
vector<int> searchYear(vector<Media*>* files, int year) {
  vector<int> results;
  for(int i = 0; i < files->size(); i++) {
    if((*files)[i]->getYear() == year) {
      results.push_back(i);
    }
  }
  return results;
}

void print(Media* file) {
  if(file->getType() == 1) { //Movie
    Movie* movie = dynamic_cast<Movie*>(file);
    cout << "Title: " << movie->getTitle() << " ";
    cout << "Released: " << movie->getYear() << " ";
    cout << "Directed by: " << movie->getDirector() << " ";
    cout << "Duration: " << movie->getDuration() << " ";
    cout << "Rating: " << movie->getRating() << "/10 ";
    cout << endl;
  } else if (file->getType() == 2) { //Game
    Game* game = dynamic_cast<Game*>(file);
    cout << "Title: " << game->getTitle() << " ";
    cout << "Released: " << game->getYear() << " ";
    cout << "Published by: " << game->getPublisher() << " ";
    cout << "Rating: " << game->getRating() << "/10 ";
    } else if (file->getType() == 3) { //Music
      Music* music = dynamic_cast<Music*>(file);
      cout << "Title: " << music->getTitle() << " ";
      cout << "Artist: " << music->getArtist() << " ";
      cout << "Released: " << music->getYear() << " ";
      cout << "Duration: " << music->getDuration() << " ";
      cout << "Published by: " << music->getPublisher() << " ";
      cout << endl;
    }
}
