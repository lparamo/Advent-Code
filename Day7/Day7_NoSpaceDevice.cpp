//lines that begin with $ are commands you executed.
/*cd means change directory : cd x moves in one level, cd .. moves out one level
and cd / switches the current directory to the outermost directory */
/*ls means list. It prints out all of the files and directories immediately contained by the current directory*/
//123 abc means that the current directory contains a file named abc with size 123.
//dir xyz means that the current directory contains a directory named xyz.

/*The total size of a directory is the sum of the sizes of the files it contains, directly or indirectly*/

//Part1: Find all of the directories with a total size of at most 100000. What is the sum of the total sizes of those directories?
//Part2: Find the smallest directory that, if deleted, would free up enough space on the filesystem to run the update. What is the total size of that directory?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>//para crear diccionarios en c++
using namespace std;


int main() {
	ifstream entrada("inputDay7.txt");
	vector<string> comando,dd;
	string linea,val,d;
	map<string, int> directorios;
	map<string, int>::iterator k;
	int sum1 = 0, sum2 = 70000000;

	directorios["/"] = 0;
	while (getline(entrada, linea)) {
		comando.clear();
		stringstream str(linea);
		while (getline(str, val, ' ')) {
			comando.push_back(val);
		}
		if (linea=="$ ls")
			continue;
		else if (linea == "$ cd /")
			d = "/";
		else if (linea == "$ cd ..") {
			stringstream s(d);
			while (getline(s, val, '/')) {
				dd.push_back(val);
			}
			d = "";
			for (int i = 0; i < dd.size() - 1; i++)
				d += dd[i] + '/';
			dd.clear();
		}
		else if (comando[0] == "$" && comando[1] == "cd") {
			d = d + comando[2]+'/';
		}
		else if (comando[0] == "dir")
			directorios[d + comando[1] + '/'] = 0;
		else {
			stringstream s(d);
			while (getline(s, val, '/')) {
				dd.push_back(val);
			}
			d = "";
			for (int i = 0; i < dd.size(); i++) {
				d += dd[i] + '/';
				directorios[d] += stoi(comando[0]);
			}
			dd.clear();
		}
	}
	int space_available = 70000000 - directorios["/"];
	int space_needed = 30000000 - space_available;
	for (k = directorios.begin(); k != directorios.end(); k++) {
		cout << k->first << ": " << k->second << endl;
		if (k->second <= 100000) sum1 += k->second;
		if (k->second >= space_needed && k->second<sum2) sum2 = k->second; 
	}
	
	cout << endl;
	cout << "Part1: " << sum1<<endl;
	cout << "Part2: " << sum2;

	return 0;
}