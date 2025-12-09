#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
	vector<string> freshRanges;
	
    ifstream fin("day5.txt");
	string temp;
	while(getline(fin, temp)) {
	    if(temp == "")
	       break;
	    
		freshRanges.push_back(temp);
	}
	
	vector<unsigned long long> ingredients;
	while(getline(fin, temp)) {
	    if(temp == "")
	       break;
	    
		ingredients.push_back(stoull(temp));
	}
	
	unsigned long long fresh = 0;
	for(unsigned long long i=0; i < ingredients.size(); i++) {
	    for(unsigned long long j=0; j<freshRanges.size(); j++) {
	        unsigned long long start = stoull(freshRanges[j].substr(0, freshRanges[j].find('-')));
	        unsigned long long end = stoull(freshRanges[j].substr(freshRanges[j].find('-')+1));
	        
	        if(ingredients[i] >= start && ingredients[i] <= end) {
	            fresh++;
	            break;
            }
        }
    }
    
    cout << fresh << endl;
    
    return 0;
}
