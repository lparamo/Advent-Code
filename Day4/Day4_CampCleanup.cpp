//Part1: In how many assignment pairs does one range fully contain the other?
//Part2: In how many assignment pairs do the ranges overlap?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int main() {
	ifstream entrada("inputDay4.txt");
	int cont1 = 0; int cont2 = 0;
	string linea, val1, val2, val3, val4;
	vector<vector<string>> content;
	vector<string> row;
	
	// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(entrada, linea)) {
		row.clear();
		stringstream str(linea);
		getline(str, val1, '-');
		row.push_back(val1);
		getline(str, val2, ',');
		row.push_back(val2);
		getline(str, val3, '-');
		row.push_back(val3);
		getline(str, val4);
		row.push_back(val4);
		content.push_back(row);
	}
	for (int i = 0; i < content.size(); i++)
	{
		if (stoi(content[i][0]) >= stoi(content[i][2]) && stoi(content[i][1]) <= stoi(content[i][3]) || stoi(content[i][0]) <= stoi(content[i][2]) && stoi(content[i][1]) >= stoi(content[i][3])) {
			cont1++;
		}
		if (stoi(content[i][1]) >= stoi(content[i][2]) && stoi(content[i][0]) <= stoi(content[i][3])) {
			cont2++;
		}
	}
	cout << cont1 << endl;
	cout << cont2 << endl;
	return 0;
}