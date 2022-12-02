//The first column: A for Rock, B for Paper, and C for Scissors
//The second column, says how the round needs to end: X means you need to lose, Y means you need to end the round in a draw, and Z means you need to win.
/*The score for a single round is the score for the shape you selected(1 for Rock, 2 for Paper, and 3 for Scissors)
+ the score for the outcome of the round (0 if you lost, 3 if the round was a draw, and 6 if you won).*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
using namespace std;
int main() {
	ifstream entrada("inputDay2.txt");
	int i;
	int n1 = 2500; int n2 = n1*2;
	char* data; data = new char[n2];
	int* RoundScores; RoundScores = new int[n1];
	int TotalScore = 0;
	for (i = 0; i < n2; i++) entrada >> data[i];
	for (i = 0; i < n2; i += 2) {
		if (data[i]=='A') {
			switch (data[i+1])
			{
			case 'X': {RoundScores[i / 2] = 3; 
				break; }
			case 'Y': {RoundScores[i / 2] = 4; 
				break; }
			case 'Z': {RoundScores[i / 2] = 8; 
				break; }

			default:
				break;
			}
		}
		else if (data[i] == 'B') {
			switch (data[i + 1])
			{
			case 'X': {RoundScores[i / 2] = 1 ;
				break; }
			case 'Y': {RoundScores[i / 2] = 5;
				break; }
			case 'Z': {RoundScores[i / 2] = 9;
				break; }

			default:
				break;
			}
		}
		else {
			switch (data[i + 1])
			{
			case 'X': {RoundScores[i / 2] = 2;
				break; }
			case 'Y': {RoundScores[i / 2] = 6; 
				break; }
			case 'Z': {RoundScores[i / 2] = 7; 
				break; }

			default:
				break;
			}
		}
	}
	for (i = 0; i < n1; i++) {
		TotalScore += RoundScores[i];
	}
	cout << TotalScore;
}