//number guessing game
#include <iostream>
#include <time.h>
using namespace std;

int main (){
  cout << "I'm thinking of a number from 1 to 10, guess what it is!\n";

  srand (time (NULL));

  int guess = 0;		//given a default value for while loop
  int r = rand () % 10 + 1;	//number from 1 to 10 is generated here

  while (guess != r){//main loop of the program, will loop until guessed number is correct
      
      while (!(cin >> guess)){//error catcher, will not allow non-numeric answers 
			cin.clear();
			cin.ignore(1000000, '\n');
			cout << "Error, not a number. Try again: \n";
	    }
		
      if (guess == r)
	    cout << "Congrats! You got it!\n";
      else if (guess > 10 || guess < 1)
	    cout << "Guess number was not between 1 and 10, try again:\n";
      else
	    cout << "Nope, try again!\n";
    }
  return 0;
}
