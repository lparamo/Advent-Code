/*The CPU has a single register, X, which starts with the value 1. It supports only two instructions:
	·addx V: takes two cycles to complete. After two cycles, the X register is increased by the value V. (V can be negative)
	·noop: takes one cycle to complete. It has no other effect */
//signal strength: the cycle number multiplied by the value of the X register
//Part1: Find the signal strength during the 20th, 60th, 100th, 140th, 180th, and 220th cycles. What is the sum of these six signal strengths?
//Part2: Render the image given by your program. What eight capital letters appear on your CRT?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int sumSS(int cycle, int X, int sum) {
	if (cycle == 20 || cycle == 60 || cycle == 100 || cycle == 140 || cycle == 180 || cycle == 220)
		sum += cycle * X;
	return sum;
}
string draw(int cycle, int X, string pixelRow) {
	if (cycle%40 == X || cycle%40 == X+1|| cycle%40== X+2) pixelRow += "#";
	else pixelRow += ".";
	return pixelRow;
}

int main() {
	ifstream entrada("inputDay10.txt");
	int cycle= 0, sum = 0, X=1;
	string linea, val, pixelRow;
	vector<string> instruction;
	while (getline(entrada, linea)) {
		instruction.clear();
		stringstream str(linea);
		while (getline(str, val, ' ')) {
			instruction.push_back(val);
		}
		if (instruction[0] == "noop") {
			cycle++;
			sum = sumSS(cycle, X, sum);
			pixelRow=draw(cycle,X,pixelRow);
			if (cycle % 40 == 0) {
				cout << pixelRow << endl;
				pixelRow = "";
			}
		}
		else {
			cycle++;
			sum = sumSS(cycle, X, sum);
			pixelRow = draw(cycle, X, pixelRow);
			if (cycle % 40 == 0) {
				cout << pixelRow << endl;
				pixelRow = "";
			}
			cycle++;
			sum = sumSS(cycle, X, sum);
			pixelRow = draw(cycle, X, pixelRow);
			if (cycle % 40 == 0) {
				cout << pixelRow << endl;
				pixelRow = "";
			}
			X += stoi(instruction[1]);
		}
	}
	cout << "Part1: "<<sum << endl;

	return 0;
}