#include <iostream>
#include <cstdlib> //zareef
#include <ctime> //zareef

using namespace std;

int main()
{
  bool playing = true;
  while(playing == true)
    {
      srand(time(NULL));
      int random = rand() % 101; //nathan
      cout << random;
      int guess = 0;
      cout << "Welcome to guessing game! Please enter a number from 0 to 100: ";
      cin >> guess;
    
      




    }
}
