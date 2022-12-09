//Simulate your complete hypothetical series of motions.How many positions does the tail of the rope visit at least once ?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>//para crear diccionarios en c++
using namespace std;
int main() {
	ifstream entrada("inputDay9.txt");
	int x1 = 0, x2 = 0, y1 = 0, y2 = 0,cont1=0; //H=(x1,y1), T=(x2,y2)
	string linea,val;
	vector<string> moves;
	map<string, int> positions;
	map<string, int>::iterator k;
	positions[to_string(x2)+","+to_string(y2)] = 1;
	while (getline(entrada, linea)) {
		moves.clear();
		stringstream str(linea);
		while (getline(str, val, ' ')) {
			moves.push_back(val);
		}
		if (moves[0] == "R") {
			for (int i = 0; i < stoi(moves[1]); i++) {
				x1++;
				if (y1 == y2 && abs(x1 - x2) > 1) x2++;
				else if (y1 != y2 && abs(x1 - x2) > 1) { y2 = y1; x2++; }
				positions[to_string(x2) + "," + to_string(y2)] += 1;
			}
		}
		else if (moves[0] == "L") {
			for (int i = 0; i < stoi(moves[1]); i++) {
				x1-=1;
				if (y1 == y2 && abs(x1 - x2) > 1) x2-=1;
				else if (y1 != y2 && abs(x1 - x2) > 1) { y2 = y1; x2-=1; }
				positions[to_string(x2) + "," + to_string(y2)] += 1;
			}
		}
		else if (moves[0] == "U") {
			for (int i = 0; i < stoi(moves[1]); i++) {
				y1++;
				if (x1 == x2 && abs(y1 - y2) > 1) y2++;
				else if (x1 != x2 && abs(y1 - y2) > 1) { x2 = x1; y2++; }
				positions[to_string(x2) + "," + to_string(y2)] += 1;
			}
		}
		else {
			for (int i = 0; i < stoi(moves[1]); i++) {
				y1-=1;
				if (x1 == x2 && abs(y1 - y2) > 1) y2-=1;
				else if (x1 != x2 && abs(y1 - y2) > 1) { x2 = x1; y2-=1; }
				positions[to_string(x2) + "," + to_string(y2)] += 1;
			}
		}
	}
	for (k = positions.begin(); k != positions.end(); k++) {
		cout << k->first << ": " << k->second << endl;
		cont1++;
	}
	cout <<"Part1: "<< cont1 << endl;
	return 0;
}