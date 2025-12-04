#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

unsigned long long getJoltage(string bank) {
    int bankLength = bank.size();
    int numbersToKeep = 12;    
           
    string result;
    int start = 0;          

    for(int i = 0; i < numbersToKeep; i++) {
        char maxDigit = '0'; // max cislo
        int maxPos = start; // pozicia max cisla
        
        for(int j = start; j <= bankLength - numbersToKeep + i; j++) { // zacina od pozicie max cisla
            if(bank[j] > maxDigit) { // ak je current vacsie ako max
                maxDigit = bank[j]; // novy max
                maxPos = j; // nova max position
            }
        }
        
        result.push_back(maxDigit);
        start = maxPos + 1;
    }

    return stoull(result);
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
