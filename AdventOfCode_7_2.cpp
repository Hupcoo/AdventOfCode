#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    vector<string> rows;
    ifstream fin("day7.txt");
    string temp;
    while(fin >> temp) {
    	rows.push_back(temp);
	}

    vector<unsigned long long> counts(rows[0].size(), 0);
    for(int x=0; x<rows[0].size(); x++) {
        if(rows[0][x] == 'S') {
			counts[x] = 1;
        	break;
		}
    }

    unsigned long long total = 0;

    for(int y=0; y < rows.size()-1; y++) {
        vector<unsigned long long> nextTimeline(rows[0].size(), 0);
        
        for(int x=0; x < rows[y].size(); x++) {
            if(counts[x] == 0) 
				continue;

            if(rows[y+1][x] == '^') {
				nextTimeline[x-1] += counts[x];
				nextTimeline[x+1] += counts[x];
            } else {
                nextTimeline[x] += counts[x];
            }
        }
        counts = nextTimeline;
    }

    for(unsigned long long count : counts) 
		total += count;
    cout << total << endl;

    return 0;
}

