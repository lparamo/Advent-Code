//entrada (calorias por elfo)
/*Los elfos se turnan para anotar el número de calorías que contienen las distintas comidas, tentempiés, raciones, etc. que han traído, un artículo por línea.
Cada elfo separa su propio inventario del inventario del elfo anterior (si lo hay) mediante una línea en blanco.*/
//Les gustaría saber cuántas calorías lleva el elfo que más calorías lleva y la suma de los tres elfos que más calorías llevan
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <list>

using namespace std;
int main() {
	ifstream entrada("inputDay1.txt");
	int sum1 = 0;
	list<int> calorias_elfo;
	int i; 
	//lectura de entrada
	string linea;
	// Obtener línea de archivo, y almacenar contenido en "linea"
	while (getline(entrada, linea)) {
		if (linea != "") {
			istringstream(linea) >> i;
			sum1 += int(i);
		}
		else {
			calorias_elfo.push_back(sum1);
			sum1 = 0;
		}
	}
	calorias_elfo.sort();
	calorias_elfo.reverse();
	list<int>::iterator pos;
	pos = calorias_elfo.begin();
	cout << *pos<<"\n";
	int suma = 0;
	suma += *pos;
	pos++;
	cout << *pos << "\n";
	suma += *pos;
	pos++;
	cout << *pos << "\n";
	suma += *pos;
	cout << suma;
}