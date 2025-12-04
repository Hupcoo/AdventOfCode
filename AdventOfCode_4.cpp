#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

unsigned int getOccupiedSpaces(int positionX, int positonY, string ) {
    unsigned int occupiedSpaces = 0;
    
    return occupiedSpaces;
}

int main() {
    int freeRolls = 0;
	vector<string> rows;
	
	unsigned int dy = [1, 1, 1, 0, -1, -1, -1, 0], 
                 dx[-1, 0, 1, 1, 1, 0, -1, -1];
	
	ifstream fin("day4.txt");
	string temp;
	while(fin >> temp) {
		rows.push_back(temp);
	}
	
	for(int = 0; i < rows.size(); i++) {
	    int occupiedSpace = 0;
	    if(i > 0 && row[i-1] == '.')
	       
	    
	    if(occupiedSpace <= 4) {
	        freeRolls += 1;
        }
    }
	
	return 0;
}
