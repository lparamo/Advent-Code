//The Elves just need to know which crate will end up on top of each stack
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
void showstacks(vector<vector<string>> content) {
	for (int i = 0; i < content.size(); i++)
	{
		for (int j = 0; j < content[i].size(); j++)
		{
			cout << content[i][j] << " ";
		}
		cout << "\n";
	}
}
vector<vector<string>> createstacks();
int main() {
	ifstream entrada("inputDay5.txt");
	int i,n,s1,s2,m;
	string linea,val;
	vector<vector<string>> content;
	vector<string> stack,row;
	//the starting stacks of crates
	content = createstacks();
	//show starting stacks
	showstacks(content);
	cout << "\n";
	//
	for (i = 0; i < 10; i++) getline(entrada, linea);
	//read procedure steps
	while (getline(entrada, linea)) {
		row.clear();
		stringstream str(linea);
		while (getline(str, val, ' ')) {
			row.push_back(val);
		}
		n = stoi(row[1]);
		s1 = stoi(row[3])-1;
		s2 = stoi(row[5])-1;
		for (i = 0; i < n;i++) {
			m = content[s1].size();
			content[s2].push_back(content[s1][m-1]);
			content[s1].pop_back();
		}
	}
	showstacks(content);
	cout << "\n";
	for (i = 0; i < 9; i++) {
		m = content[i].size();
		cout<<content[i][m-1];
	}
	
	return 0;
}
vector<vector<string>> createstacks() {
	vector<string>stack;
	vector<vector<string>> content;
	stack.clear();//1
	stack.push_back("D");
	stack.push_back("H");
	stack.push_back("N");
	stack.push_back("Q");
	stack.push_back("T");
	stack.push_back("W");
	stack.push_back("V");
	stack.push_back("B");
	content.push_back(stack);
	stack.clear();//2
	stack.push_back("D");
	stack.push_back("W");
	stack.push_back("B");
	content.push_back(stack);
	stack.clear();//3
	stack.push_back("T");
	stack.push_back("S");
	stack.push_back("Q");
	stack.push_back("W");
	stack.push_back("J");
	stack.push_back("C");
	content.push_back(stack);
	stack.clear();//4
	stack.push_back("F");
	stack.push_back("J");
	stack.push_back("R");
	stack.push_back("N");
	stack.push_back("Z");
	stack.push_back("T");
	stack.push_back("P");
	content.push_back(stack);
	stack.clear();//5
	stack.push_back("G");
	stack.push_back("P");
	stack.push_back("V");
	stack.push_back("J");
	stack.push_back("M");
	stack.push_back("S");
	stack.push_back("T");
	content.push_back(stack);
	stack.clear();//6
	stack.push_back("B");
	stack.push_back("W");
	stack.push_back("F");
	stack.push_back("T");
	stack.push_back("N");
	content.push_back(stack);
	stack.clear();//7
	stack.push_back("B");
	stack.push_back("L");
	stack.push_back("D");
	stack.push_back("Q");
	stack.push_back("F");
	stack.push_back("H");
	stack.push_back("V");
	stack.push_back("N");
	content.push_back(stack);
	stack.clear();//8
	stack.push_back("H");
	stack.push_back("P");
	stack.push_back("F");
	stack.push_back("R");
	content.push_back(stack);
	stack.clear();//9
	stack.push_back("Z");
	stack.push_back("S");
	stack.push_back("M");
	stack.push_back("B");
	stack.push_back("L");
	stack.push_back("N");
	stack.push_back("P");
	stack.push_back("H");
	content.push_back(stack);
	return content;
}