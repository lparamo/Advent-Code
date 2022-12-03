/*Lowercase item types a through z have priorities 1 through 26.
Uppercase item types A through Z have priorities 27 through 52.*/
/*Find the item type that corresponds to the badges of each three-Elf group.
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
	int i, j,k; int sump = 0;
	char item;
	string abc = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string linea1,linea2,linea3;
	// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(entrada, linea1)) {
		getline(entrada, linea2);
		getline(entrada, linea3);
		for (i = 0; i < linea1.length(); i++) {
			for (j = 0; j < linea2.length();j++) {
				if (linea1[i] == linea2[j]){
					for (k = 0; k < linea3.length(); k++) {
						if (linea1[i] == linea3[k]) {
							item = linea1[i];
							break;
						}
					}
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