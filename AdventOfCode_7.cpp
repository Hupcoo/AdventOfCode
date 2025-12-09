#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int split = 0;
	vector<string> rows;
	
	ifstream fin("day7.txt");
	string temp;
	while(fin >> temp) {
		rows.push_back(temp);
	}
	
	for(int y=0; y<rows.size()-1; y++) {
		for(int x=0; x<rows[y].size(); x++) {
			if(rows[y][x] == '|' && rows[y+1][x] == '^') {
				rows[y+1][x-1] = '|';
				rows[y+1][x+1] = '|';
				split+=2;
			}
			if((rows[y][x] == '|' || rows[y][x] == 'S') && rows[y+1][x] != '^') {
				rows[y+1][x] = '|';
			} 
		}
	}
	
    cout << split << endl;
	return 0;
}
