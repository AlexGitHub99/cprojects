#include <iostream>
#include <cstring>
#include <vector>
#include <math.h>
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
  
  //delete (*files)[1];
  //files->erase(files->begin() + 1);

  cout << "Welcome to media list! Use commands add, search, delete, and quit. You can add movie, game, and music files" << endl;
  bool running = true;
  while(running = true) {
    cin.clear();
    char input[15] = {};
    vector<int> results;
    cin.getline(input, 15);
    if(strcmp(input, "add") == 0) {
      cout << "Which media type are you adding? Choose movie, game, or music" << endl;
      cin.getline(input, 15);
      cout << "Please enter the information in the following format (keep individual fields to 14 characters or less): " << endl;
      if(strcmp(input, "movie") == 0) {
	cout << "title director year duration_in_seconds rating_out_of_ten" << endl;
	char title[15];
	cin.get(title, 15, ' ');
	cin.get();
	char director[15];
	cin.get(director, 15, ' ');
	cin.get();
	char yearText[15];
	cin.get(yearText, 15, ' ');
	cin.get();
	char durationText[15];
	cin.get(durationText, 15, ' ');
	cin.get();
	char ratingText[15];
	cin.get(ratingText, 15, '\n');
	cin.get();
	int year = 0;
	int duration = 0;
	int rating = ratingText[0] - 48;
	for(int i = 0; i < strlen(yearText); i++) {
	  year += (yearText[i] - 48) * pow(10, strlen(yearText) - i - 1);
	}
	for(int i = 0; i < strlen(durationText); i++) {
	  duration += (durationText[i] - 48) * pow(10, strlen(durationText) - i - 1);
	}
	addMovie(files, title, director, year, duration, rating);
	cout << "Movie added!" << endl;
      } else if(strcmp(input, "game") == 0) {
	cout << "title year publisher rating" << endl;
	char title[15];
	cin.get(title, 15, ' ');
	cin.get();
	char yearText[15];
	cin.get(yearText, 15, ' ');
	cin.get();
	char publisher[15];
	cin.get(publisher, 15, ' ');
	cin.get();
	char ratingText[15];
	cin.get(ratingText, 15, '\n');
	cin.get();
	int year = 0;
	int rating = ratingText[0] - 48;
	for(int i = 0; i < strlen(yearText); i++) {
	  year += (yearText[i] - 48) * pow(10, strlen(yearText) - i - 1);
	}
	addGame(files, title, year, publisher, rating);
	cout << "Game added!" << endl;
      } else if(strcmp(input, "music") == 0) {
	cout << "title artist year duration_in_seconds rating" << endl;
	char title[15];
	cin.get(title, 15, ' ');
	cin.get();
	char artist[15];
	cin.get(artist, 15, ' ');
	cin.get();
	char yearText[15];
	cin.get(yearText, 15, ' ');
	cin.get();
	char durationText[15];
	cin.get(durationText, 15, ' ');
	cin.get();
	char publisher[15];
	cin.get(publisher, 15, '\n');
	cin.get();
	int year = 0;
	int duration = 0;
	for(int i = 0; i < strlen(yearText); i++) {
	  year += (yearText[i] - 48) * pow(10, strlen(yearText) - i - 1);
	}
	for(int i = 0; i < strlen(durationText); i++) {
	  duration += durationText[i] - 48;
	}
	addMusic(files, title, artist, year, duration, publisher);
	cout << "Music added!" << endl;
      }
    } else if(strcmp(input, "search")  == 0) {
      cout << "Would you like to search by title or year?" << endl;
      cin.getline(input, 15);
      cout << "Please enter your search value" << endl;
      if(strcmp(input, "title") == 0) {
	cin.getline(input, 15);
	results = searchTitle(files, input);
      } else if(strcmp(input, "year") == 0) {
	cin.getline(input, 15);
	int year = 0;
	for(int i = 0; i < strlen(input); i++) {
	  year += (input[i] - 48) * pow(10, strlen(input) - i - 1);
	}
	results = searchYear(files, year);
      }
      if(results.empty() == true) {
	cout << "No results found" << endl;
      } else {
	for(int i = 0; i < results.size(); i++) {
	  print((*files)[results[i]]);
	}
      }
    } else if(strcmp(input, "delete") == 0) {
      cout << "Would you like to delete by title or year?" << endl;
      cin.getline(input, 15);
      cout << "Please enter the title/year of the file you want to delete" << endl;
      if(strcmp(input, "title") == 0) {
	cin.getline(input, 15);
	results = searchTitle(files, input);
      } else if(strcmp(input, "year") == 0) {
	cin.getline(input, 15);
	int year = 0;
	for(int i = 0; i < strlen(input); i++) {
	  year += (input[i] - 48) * pow(10, strlen(input) - i - 1);
	}
	results = searchYear(files, year);
      }
      if(results.empty() == true) {
	cout << "No results found" << endl;
      } else {
	for(int i = 0; i < results.size(); i++) {
	  print((*files)[results[i]]);
	}
	cout << "Are you sure you want to delete these files? y/n" << endl;
	cin.getline(input, 15);
	if(input[0] = 'y') {
	  for(int i = 0; i < results.size(); i++) {
	    delete (*files)[results[i] - i];
	    files->erase(files->begin() + results[i] - i);
	  }
	}
      }
    } else if(strcmp(input, "quit") == 0) {
      running = false;
      for(int i = 0; i < files->size(); i++) {
	delete (*files)[i];
      }
    }
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
    cout << endl;
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
