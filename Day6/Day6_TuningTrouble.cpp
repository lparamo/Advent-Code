//The start of a packet is indicated by a sequence of four characters that are all different
/*Your subroutine needs to identify the first position where the four most recently received characters were all different.
Specifically, it needs to report the number of characters from the beginning of the buffer to the end of the first such four-character marker.*/
/*A start-of-message marker is just like a start-of-packet marker, except it consists of 14 distinct characters rather than 4.*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
	ifstream entrada("inputDay6.txt");
	string buffer;
	int s, x=0, y=0, c=0;
	getline(entrada, buffer);
	s=buffer.size();
	for (int i = 0; i < s; i++) {
		if (buffer[i] != buffer[i + 1] && buffer[i] != buffer[i + 2] && buffer[i] != buffer[i + 3] && buffer[i + 1] != buffer[i + 2] && buffer[i + 1] != buffer[i + 3] && buffer[i + 2] != buffer[i + 3]) {
			x = i + 4;
			break;
		}	
	}
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < 13 ; j++) {
			for (int k = j+1; k < 13;k++) {
				if (buffer[i+j] == buffer[i+k]) {
					c++;
					break;
				}
			}
			if (c != 0) break;
		}
		if (c == 0) {
			y = i + 14;
			break;
		}
		c = 0;
	}
	cout << "Part 1: " << x << endl;
	cout << "Part 2: " << y << endl;
	return 0;
}