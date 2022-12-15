/*Starting items: lists your worry level for each item the monkey is currently holding in the order they will be inspected.
Operation:  shows how your worry level changes as that monkey inspects an item.
(An operation like new = old * 5 means that your worry level after the monkey inspected the item is five times whatever your worry level was before inspection.)
Test:  shows how the monkey uses your worry level to decide where to throw an item next.*/

//ONLY FOR MY INPUT :)
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>//para crear diccionarios en c++
using namespace std;

map<int, vector<int>> readInput(string input);
int worry(long long int item, string op, int x) {
	if (op == "*")
		item = item * x;
	else
		item += x;
	//item = floor(item / 3); //Part1
	item %= (11*3*5*7*19*2*13*17); 
	return item;
}

int main() {
	map<int, vector<int>> monkeys = readInput("inputDay11.txt");
	map<int, long long int> inspected;
	bool divisible;
	long long int item,n,max=0,max2=0;

	for (int i = 0; i < 10000; i++) {
		/*for (int k = 0; k < monkeys.size(); k++) {
			for (int j = 0; j < monkeys[k].size(); j++)
				cout << monkeys[k][j] << " ";
			cout << endl;
		}
		cout << "----------------------------------------------" << endl;*/

		//Monkey 0
		for (int j = 0; j < monkeys[0].size(); j++) {
			item = worry(monkeys[0][j], "*", 17);
			if (item % 11 == 0)
				monkeys[2].push_back(item);
			else monkeys[3].push_back(item);
		}
		n = monkeys[0].size();
		inspected[0] += n;
		for (int j = 0; j < n; j++)
			monkeys[0].pop_back();
		//Monkey 1
		for (int j = 0; j < monkeys[1].size(); j++) {
			item = worry(monkeys[1][j], "+", 7);
			if (item % 3 == 0)
				monkeys[6].push_back(item);
			else monkeys[5].push_back(item);
		}
		n = monkeys[1].size();
		inspected[1] += n;
		for (int j = 0; j < n; j++)
			monkeys[1].pop_back();
		//Monkey 2
		for (int j = 0; j < monkeys[2].size(); j++) {
			item = worry(monkeys[2][j], "*", monkeys[2][j]);
			if (item % 5 == 0)
				monkeys[1].push_back(item);
			else monkeys[7].push_back(item);
		}
		n = monkeys[2].size();
		inspected[2] += n;
		for (int j = 0; j < n; j++)
			monkeys[2].pop_back();
		//Monkey 3
		for (int j = 0; j < monkeys[3].size(); j++) {
			item = worry(monkeys[3][j], "+", 1);
			if (item % 7 == 0)
				monkeys[2].push_back(item);
			else monkeys[7].push_back(item);
		}
		n = monkeys[3].size();
		inspected[3] += n;
		for (int j = 0; j < n; j++)
			monkeys[3].pop_back();
		//Monkey 4
		for (int j = 0; j < monkeys[4].size(); j++) {
			item = worry(monkeys[4][j], "*", 3);
			if (item % 19 == 0)
				monkeys[0].push_back(item);
			else monkeys[3].push_back(item);
		}
		n = monkeys[4].size();
		inspected[4] += n;
		for (int j = 0; j < n; j++)
			monkeys[4].pop_back();
		//Monkey 5
		for (int j = 0; j < monkeys[5].size(); j++) {
			item = worry(monkeys[5][j], "+", 4);
			if (item % 2 == 0)
				monkeys[6].push_back(item);
			else monkeys[4].push_back(item);
		}
		n = monkeys[5].size();
		inspected[5] += n;
		for (int j = 0; j < n; j++)
			monkeys[5].pop_back();
		//Monkey 6
		for (int j = 0; j < monkeys[6].size(); j++) {
			item = worry(monkeys[6][j], "+", 8);
			if (item % 13 == 0)
				monkeys[4].push_back(item);
			else monkeys[0].push_back(item);
		}
		n = monkeys[6].size();
		inspected[6] += n;
		for (int j = 0; j < n; j++)
			monkeys[6].pop_back();
		//Monkey 7
		for (int j = 0; j < monkeys[7].size(); j++) {
			item = worry(monkeys[7][j], "+", 6);
			if (item % 17 == 0)
				monkeys[1].push_back(item);
			else monkeys[5].push_back(item);
		}
		n = monkeys[7].size();
		inspected[7] += n;
		for (int j = 0; j < n; j++)
			monkeys[7].pop_back();
	}
	for (int i = 0; i < inspected.size(); i++) {
		cout << "Monkey" << i << ": " << inspected[i] << endl;
		if (inspected[i] >= max) { max2 = max; max = inspected[i]; }
		else if (inspected[i] >= max2) max2 = inspected[i];
	}
	cout <<"\nPart2: " << max * max2 << endl;
	return 0;
}

map<int, vector<int>> readInput(string input) {
	ifstream entrada(input);
	string line, line1, line2, val;
	vector<string> notes, monk;
	map<int, vector<int>> monkeys;

	while (getline(entrada, line)) {
		monk.clear();
		stringstream str(line);
		getline(str, val, ' ');
		monk.push_back(val);
		getline(str, val, ':');
		monk.push_back(val);

		getline(entrada, line1);
		notes.clear();
		stringstream str1(line1);
		getline(str1, val, ':');
		notes.push_back(val);
		while (getline(str1, val, ',')) {
			notes.push_back(val);
		}

		for (int i = 1; i < notes.size(); i++) {
			monkeys[stoi(monk[1])].push_back(stoi(notes[i]));
		}

		getline(entrada, line2);
		getline(entrada, line2);
		getline(entrada, line2);
		getline(entrada, line2);
		getline(entrada, line2);

	}
	return monkeys;
}