//Simulate your complete hypothetical series of motions. How many positions does the tail of the rope visit at least once ?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <array>
#include <map>//para crear diccionarios en c++
using namespace std;

int main() {
	ifstream entrada("inputDay9.txt");
	array<int, 20> coord{}; //H=(coord[0],coord[1]), part1: T=(coord[2],coord[3]), part2: T=(coord[18],coord[19])
	int cont1=0,cont2=0; 
	string linea,val;
	vector<string> moves;
	map<string, int> positions1,positions2;
	map<string, int>::iterator k,l;
	while (getline(entrada, linea)) {
		moves.clear();
		stringstream str(linea);
		while (getline(str, val, ' ')) {
			moves.push_back(val);
		}
		for (int i = 0; i < stoi(moves[1]); i++) {
			if (moves[0] == "R") 
				coord[0]++;
			else if (moves[0] == "L") 
				coord[0] -= 1;
			else if (moves[0] == "U") 
				coord[1]++;
			else 
				coord[1] -= 1;
			for (int j = 2; j < 19; j += 2) {
				if (coord[j]==coord[j-2]) {
					if (coord[j - 1] - coord[j + 1] == 2) coord[j + 1]++;
					else if (coord[j - 1] - coord[j + 1] == -2) coord[j + 1]-=1;
				}
				else if (coord[j+1] == coord[j - 1]) {
					if (coord[j - 2] - coord[j] == 2) coord[j]++;
					else if (coord[j - 2] - coord[j] == -2) coord[j] -= 1;
				}
				else if ((abs(coord[j - 1] - coord[j + 1]) + abs(coord[j - 2] - coord[j])) > 2) {
					if (coord[j - 2] > coord[j]) {
						if (coord[j - 1] > coord[j + 1]) {
							coord[j]++; coord[j+1]++;
						}
						else {
							coord[j]++; coord[j + 1]-=1;
						}
					}
					else {
						if (coord[j - 1] > coord[j + 1]) {
							coord[j]-=1; coord[j + 1]++;
						}
						else {
							coord[j]-=1; coord[j + 1] -= 1;
						}
					}
				}
			}
			positions1[to_string(coord[2]) + "," + to_string(coord[3])] += 1;
			positions2[to_string(coord[18]) + "," + to_string(coord[19])] += 1;
		}
	}
	for (k = positions1.begin(); k != positions1.end(); k++) {
		cont1++;
	}
	for (l = positions2.begin(); l != positions2.end(); l++) {
		cont2++;
	}
	cout << "Part1: " << cont1 << endl;
	cout << "Part2: " << cont2 << endl;
	return 0;
}
