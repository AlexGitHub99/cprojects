#include <iostream>
#include <cstring>

using namespace std;

main() {
  char string[81];
  char rvString[81];
  
  while(true) {
    cout << "Please enter no more than 80 characters of text";
    cin.get(string, 81);
    while(cin.get() != '\n');
    for(int i = 0; i < 81; i ++) {
      if(string[i] != '\0') {
	rvString[80 - i] = string[i];
      }
    }
    cout << string << "\n";
    cout << rvString << "\n";
		      
  }

}
