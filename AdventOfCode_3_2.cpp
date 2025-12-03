#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int getJoltage(string bank) {
    int bankLength = bank.length();
    int maxJoltage = 0;
    
    for(int i=0; i < bankLength - 1; i++) {
        int firstVal = bank[i] - '0';
        
        for(int j=i+1; j<bankLength; j++) {
            int secondVal = bank[j] - '0';
            int joltage = firstVal * 10 + secondVal;
            
            if(maxJoltage < joltage) {
                maxJoltage = joltage;
            }
        }
    }
    
    return maxJoltage;
}

int main() {
	unsigned long long totalJoltage = 0;
	vector<string> joltages;
	
	ifstream fin("day3.txt");
	string temp;
	while(fin >> temp) {
		joltages.push_back(temp);
	}
	
	for(int i=0; i < joltages.size(); i++) {
	    totalJoltage += getJoltage(joltages[i]);
    }
	
	cout << totalJoltage << endl;
	
	return 0;
}
