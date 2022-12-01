//entrada (calorias por elfo)
/*Los elfos se turnan para anotar el número de calorías que contienen las distintas comidas, tentempiés, raciones, etc. que han traído, un artículo por línea.
Cada elfo separa su propio inventario del inventario del elfo anterior (si lo hay) mediante una línea en blanco.*/
//les gustaría saber cuántas calorías lleva el elfo que más calorías lleva
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
int main() {
	ifstream entrada("inputDay1.txt");
	int sum1 = 0; int sum2=0;
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
			if (sum1 > sum2) {
				sum2 = sum1;
				sum1 = 0;
			}
			else sum1 = 0;
		}
	}
	cout << sum2;
}