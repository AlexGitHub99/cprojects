#include <iostream>
#include <cstring>

using namespace std;

main() {
  char input[81];
  char rvString[81];
  while(true) {
    cout << "Please enter no more than 80 characters of text";
    cin.get(input, 81);
    while(cin.get() != '\n');
    char string[strlen(input)];
    int j = 0;
    for(int i = 0; i < 81; i++) {
      if(input[i] >= 65 && input[i] <= 90) { // it's a capital letter 
	string[j] = input[i] + 32; //converts the letter into a lowercase before copying it over into string
	j++;
      } else if (input[i] >= 97 && input[i] <= 122) { //it's a lowercase letter
	string[j] = input[i];
	j++;
      } else if (input[i] == '\0') { // it's a null terminating character
	string[j] = input[i];
      }
    }
    //writing = false;
    //int j = 0;
    //for(int i = 0; i < 81; i++) {
    //if(writing == true && string[80 - i] !=  ) {
    //	rvString[j] = string[80 - i];
    //	j++
    //}
    //if(string[80 - i] == '\0') {
    //	writing = true;
    //	
    //}
    //if(writing == true) {
    //	rvString[j] = string[80 - i - 1];
    //	j++
    //}
    cout << string << "\n";
    
    //cout << rvString << "\n";
		      
  }

}
