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
	
	int dy[] = {1, 1, 1, 0, -1, -1, -1, 0},
        dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
	
	ifstream fin("day4.txt");
	string temp;
	while(fin >> temp) {
		rows.push_back(temp);
	}
	
	for(int y = 0; y < rows.size(); y++) {
		for(int x = 0; x < rows[y].length(); x++) {
			if(rows[y][x] != '@')
				continue;
				
			int occupiedSpace = 0;
		    
		    for(int d = 0; d < 8; d++) {
				if ((x == 0 && dx[d] == -1) || (y == 0 && dy[d] == -1) || 
				    (x == rows[y].length() - 1 && dx[d] == 1) || (y == rows.size() - 1 && dy[d] == 1))
				    continue;
				
				int checkPosY = y + dy[d],
					checkPosX = x + dx[d];
				
		    	if(rows[checkPosY][checkPosX] == '@') {
		    		occupiedSpace++;
				}
				if(occupiedSpace > 3) {
					break;
				}
			}     
		       
		    if(occupiedSpace < 4) {
		        freeRolls += 1;
	        }
		} 
    }
    
    cout << freeRolls << endl;
	
	return 0;
}
