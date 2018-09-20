#include <iostream>
#include <cstring>
//Created by: Alex King
//Last modified: 9/20/2018
//This program creates a game of tic tac toe using a 2 dimensional array,

using namespace std;
void printBoard(int board[3][3]);
void resetBoard(int board[3][3]);
bool inputBoard(int board[3][3], int column, char row, int turn);
bool checkInput(char input[2]);
int checkWin(int board[3][3]);

const int X = 1;
const int O = 2;

int main() {

  int board[3][3];
  bool playing = true;
  int turn = O;
  int xWins = 0;
  int oWins = 0;
    
  resetBoard(board);
  
  while(playing == true) { //main loop
    printBoard(board);

    // switch turn
    if(turn == X) {
      turn = O;
      cout << "It's O's turn" << endl;
    } else {
      turn = X;
      cout << "It's X's turn" << endl;
    }
      
    cout << "Please enter a place on the board" << endl;
    char input[2];
    cin.get(input, 3);
    while(cin.get() != '\n'); //eats characters until a return character is reached, eats it, then stops

    while(!checkInput(input)) {//repeats until input is valid
	cout << "Invalid input, please enter a number from 1 to 3 followed by a letter from a to c, for example, 1a" << endl;
	cin.get(input, 3);
	while(cin.get() != '\n');
    }
    
    while(!inputBoard(board, input[0], input[1], turn)) { //repeats until move is valid
      cout << "There's already a move there" << endl;
      
      cin.get(input, 3);
      while(cin.get() != '\n');
      
      while(!checkInput(input)) {//repeats until input is valid
	cout << "Invalid input, please enter a number followed by a letter, for example, 1a" << endl;
	cin.get(input, 3);
	while(cin.get() != '\n');
      }
    }
    
    if(checkWin(board) != 0) { //its a win or tie
      if(checkWin(board) == 1) { //x win
	cout << "X wins!" << endl;
	xWins++;
      } else if(checkWin(board) == 2) {//o win
	cout << "O wins!" << endl;
	oWins++;
      } else if(checkWin(board) == 3) {//it's a tie
	cout << "It's a tie" << endl;
      }
      cout << "X wins: " << xWins << " O Wins: " << oWins << endl;
      resetBoard(board);
      cout << "Do you want to play again? y/n" << endl;
      char yn;
      cin >> yn;
      while(cin.get() != '\n');
      if(yn == 'n') {//stop playing
	playing = false;
      }
    }
  }
}

void printBoard(int board[3][3]) {//prints each place in the board and column numbers and row letters 
  cout << "  1 2 3" << endl;
  for(int i = 0; i < 3; i++) { //go though each row
    //prints outs row letters
    if(i == 0) {
      cout << "a ";
	} else if (i == 1) {
      cout << "b ";
    } else {
      cout << "c ";
    }
    for(int j = 0; j < 3; j++) {//go through each column
      if(board[j][i] == X) {//its an X
	cout << "X";
	  } else if(board[j][i] == O) {//its an O
	cout << "O";
      } else {//its empty
	cout << " ";
	  }
      cout << " "; //space between 
    }
    cout << endl;
  }
  cout << endl;
}

void resetBoard(int board[3][3]) {//sets all places in the board to empty
  for(int i = 0; i < 3; i++) {
    for(int j = 0; j < 3; j++) {
      board[j][i] = 0; //sets the given board place to empty
    }
  }
}

bool inputBoard(int board[3][3], int column, char row, int turn) {
  //since column is passed in as a character, the int value will be of the ascii character. This converts that value into the character's numerical value
  column = column - 48;
  
  if(row == 'a') {//row is a
    if(board[column - 1][0] == 0) {//place is empty
    board[column - 1][0] = turn;
    return true;
    }
  } else if (row == 'b') {//row is b
    if(board[column - 1][1] == 0) { //place is empty
    board[column - 1][1] = turn;
    return true;
    }
  } else {//row is c
    if(board[column - 1][2] == 0) { //place is empty
    board[column - 1][2] = turn;
    return true;
    }
  }
  return false; //place was not empty
}

bool checkInput(char input[2]) {//checks that the input is formatted correctly (letter followed by number)
  if((input[0] == '1' || input[0] == '2' || input[0] == '3') && //the first value of the input is a 1, 2, or 3
     (input[1] == 'a' || input[1] == 'b' || input [1] == 'c')) { //the second value of the input is an a, b, or c
     return true;
   } else {
     return false;
   }
}

int checkWin(int board[3][3]) { //checks if a player has won or if it's a tie, returns 0 for no, 1 for an X win, 2 for an O win, and 3 for a tie
  //Check X wins
  if(board[0][0] == X && board[1][0] == X && board[2][0] == X || //across the top
     board[0][1] == X && board[1][1] == X && board[2][1] == X || //across the middle
     board[0][2] == X && board[1][2] == X && board[2][2] == X || //across the bottom

     board[0][0] == X && board[0][1] == X && board[0][2] == X || // down the left
     board[1][0] == X && board[1][1] == X && board[1][2] == X || // down the middle
     board[2][0] == X && board[2][1] == X && board[2][2] == X || //down the right

     board[0][0] == X && board[1][1] == X && board[2][2] == X || // diagonal top left to bottom right
     board[0][2] == X && board[1][1] == X && board[2][0] == X ) { // diagonal top right to bottom left
    return 1;
      //Check O wins
  } else if (
     board[0][0] == O && board[1][0] == O && board[2][0] == O |//across the top
     board[0][1] == O && board[1][1] == O && board[2][1] == O || //across the middle
     board[0][2] == O && board[1][2] == O && board[2][2] == O || //across the bottom

     board[0][0] == O && board[0][1] == O && board[0][2] == O || //down the left
     board[1][0] == O && board[1][1] == O && board[1][2] == O || //down the middle
     board[2][0] == O && board[2][1] == O && board[2][2] == O || //down the right

     board[0][0] == O && board[1][1] == O && board[2][2] == O || //diagonal top left to bottom right
     board[0][2] == O && board[1][1] == O && board[2][0] == O ) {//diagonal top right to bottom left
    return 2;
  } else {
    //check for an empty place
    for(int i = 0; i < 3; i++) {
      for(int j = 0; j < 3; j++) {
	if(board[i][j] == 0) { //nobody has won or tied as there's still an empty place
	   return 0; 
	}
      }
    }
    return 3; //since nobody has won and the board is full, it's a tie
  }
}

