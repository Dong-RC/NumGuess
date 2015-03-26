//There are 3 numbers generated randomly by computer
//And the player inputs his guesses 
//Computer will compare the result, and generate "*A*B"
//where A represents that the number and the position are both correct, B represents that the number is correct but the position not.
//Player have 7 chancese in one game, if the outout is "3A0B" within 7 times, player wins, otherwise, loses.
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{	int bothCorrect = 0, //number and position are both correct
		numCorrect = 0, //number is correct but position not
		times,  //chances that have been used
		total = 0, //times of game the player have played
		win = 0, //win times
		lose = 0,  // loses times
	    ran[3], //3 random numbers
		guess[3], // 3 guessed numbers
		i, j;
	char play; //whether continue playing
	
	srand(time(NULL));
	
	cout << "Let's play a game? (Y/N) ";
	cin >> play;
	
	while (play == 'Y') {
		times = 1;
	
		ran[0] = rand() * 10 / (RAND_MAX + 1);
		ran[1] = rand() * 10 / (RAND_MAX + 1);
		ran[2] = rand() * 10 / (RAND_MAX + 1);
	
		while (ran[1] == ran[0]) ran[1] = rand() * 10 / (RAND_MAX + 1); 
		while (ran[2] == ran[0] || ran[2] == ran[1]) ran[2] = rand() * 10 / (RAND_MAX + 1); //3 random numbers should be different from each other
		
		while (times <=7) {
			cout << "Please input your guess:\n";
			cin >> guess[0] >> guess[1] >> guess[2];
			
			bothCorrect = 0;
			numCorrect = 0;
			
			for (i = 0; i <3; ++i) {
				if (guess[i] == ran[i]) ++bothCorrect; // number and position are both correct
				else for (j = 0, j != i; j <3; ++j) 
						if (guess[i] == ran[j]) ++numCorrect;  // number is correct but position not
			}
			cout << bothCorrect << 'A' << numCorrect << 'B' << "\n";
				
			if (bothCorrect == 3) {
				cout << "Congratulations! You win!" << endl;
				++win;
				times = 7; 
			}
			++times;
		}
		if (bothCorrect != 3) {
			cout << "Sorry, you didn't make it in given times, the correct anwser is: " << ran[0] << ran[1] << ran[2] << endl;
			++lose;
		}
		++total;
		
		cout << "Let's play a game? (Y/N) ";
		cin >> play;
	}
	cout << "You have played " << total << " times, " << win << " wins and " << lose << " loses." << endl;
	
	return 0;
}
