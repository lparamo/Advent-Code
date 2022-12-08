/*A tree is visible if all of the other trees between it and an edge of the grid are shorter than it. 
Only consider trees in the same row or column; that is, only look up, down, left, or right from any given tree.*/
//Part1: How many trees are visible from outside the grid?
//A tree's scenic score is found by multiplying together its viewing distance in each of the four directions.
//Part2: Consider each tree on your map. What is the highest scenic score possible for any tree?
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
int main() {
	ifstream entrada("inputDay8.txt");
	string fila;
	vector<string> grid;
	int x1 = 0, x2=0, y1 = 0,y2=0, cont1 = 0, cont2 = 0;
	int s1 = 0, s2 = 0, s3 = 0, s4 = 0,score=0;
	while (getline(entrada, fila)) {
		grid.push_back(fila);
		cont1 += 2;
	}
	cont1 += (grid[0].size() - 2) * 2;
	for (int i = 1; i < grid.size() - 1; i++) {
		for (int j = 1; j < grid[i].size() - 1; j++) {
			for (int k = j-1; k >-1; k-=1) { 
				if (grid[i][j] <= grid[i][k]) {
					s1 = j - k;
					x1++;
					break;
				}
				else s1 = j;
			}
			for (int k = j + 1; k < grid[i].size(); k++) { 
				if (grid[i][j] <= grid[i][k]) {
					s2 = k - j;
					x2++;
					break;
				}
				else s2 = grid[i].size() -j -1;
			}
			for (int k =i-1; k >-1; k-=1) {
				if (grid[i][j] <= grid[k][j]) {
					s3 = i - k;
					y1++;
					break;
				}
				else s3 = i;
			}
			for (int k = i + 1; k < grid.size(); k++) {
				if (grid[i][j] <= grid[k][j]) {
					s4 = k - i;
					y2++;
					break;
				}
				else s4 = grid.size()-i -1;
			}
			if (x1 == 0 || x2 == 0 || y1 == 0 || y2 == 0) cont1++;
			x1 = 0; x2 = 0; y1 = 0; y2 = 0;
			score = s1 * s2 * s3 * s4;
			if (score > cont2) cont2 = score;
		}
	}
	cout << "Part1: " << cont1 << endl;
	cout << "Part2: " << cont2 << endl;
	return 0;
}