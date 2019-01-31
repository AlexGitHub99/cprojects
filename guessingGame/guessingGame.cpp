#include <iostream>
//friend: Zareef class: C++ programming 5
//I am using their code with their permission
//Imports two libraries for the random number generation and seed generation based on time
#include <cstdlib>
#include <ctime>
#include <string>
//End of used code

using namespace std;

int main()
{
  bool playing = true;
  while(playing == true)
    {
      srand(time(NULL));
      //friend: Nathan class: C++ programming 5
      //I am using their code with their permission (It's one line)
      //Generates a random number then gets 
      int random = rand() % 101;
      //End of used code
      int tries = 0;
      cout << "Welcome to guessing game! Please enter a number from 0 to 100: ";
      bool correct = false;
      while(correct == false) { //Take guesses from the user until they're correct
	int guess = 0;
	cin >> guess; //Takes a guess from the user
	//Code from stack overflow users: JavaRunner, Arnov Borborah, my dad also helped: parent: Steve
	//http://stackoverflow.com/questions/39282953/how-to-reset-stdcin-when-using-it
	//This code clears and resets cin to eleimate an error when the user enters a large number or non integer as a guess
	while(cin.fail()) {
	  cin.clear(); //Clears cin to eleminate error when the user enters a large number or non integer as a guess
	  cin.ignore();
	  cin >> guess;
	}
	//End of used code
	tries++;
	if(guess > random) {
	  cout << "Too high! Guess again!" << endl;
	    } else if(guess < random) {
	  cout << "Too low! Guess again!" << endl;
	} else { //User guessed correctly
	  correct = true;
	  cout << "Correct! It took you " << tries << " tries to guess the number!" << endl;
	  cout << "Would you like to play again? y/n ";
	  char answer = 'a'; 
	  while(answer != 'n' && answer != 'y') {//Keep taking answers until it's a y or n
	    cin >> answer;
	    if(answer == 'n') { //End game
		   playing = false;
		 }
	  }
	}
      }
    }
}
