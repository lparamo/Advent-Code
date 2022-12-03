/*Lowercase item types a through z have priorities 1 through 26.
Uppercase item types A through Z have priorities 27 through 52.*/
/*Find the item type that appears in both compartments of each rucksack.
What is the sum of the priorities of those item types?*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>
#include <conio.h>
using namespace std;
int main() {
	ifstream entrada("inputDay3.txt");
	int i, j; int l = 0; int sump = 0;
	char item;
	string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	//lectura de entrada
	string linea;
	// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(entrada, linea)) {
		l = linea.length();
		for (i = 0; i < l / 2; i++) {
			for (j = l/2; j < l; j++) {
				if (linea[i] == linea[j]) {
					item = linea[i];
					break;
				}
			}
		}
		//cout << item << endl;
		for (i = 0; i < 52; i++) {
			if (item == abc[i]) {
				sump += i + 1;
				//cout << sump << endl;
				break;
			}
		}
	}
	cout << sump;

	return 0;
}