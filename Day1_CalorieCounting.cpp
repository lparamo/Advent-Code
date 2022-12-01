//entrada (calorias por elfo)
/*Los elfos se turnan para anotar el n�mero de calor�as que contienen las distintas comidas, tentempi�s, raciones, etc. que han tra�do, un art�culo por l�nea.
Cada elfo separa su propio inventario del inventario del elfo anterior (si lo hay) mediante una l�nea en blanco.*/
//les gustar�a saber cu�ntas calor�as lleva el elfo que m�s calor�as lleva
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
	// Obtener l�nea de archivo, y almacenar contenido en "linea"
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