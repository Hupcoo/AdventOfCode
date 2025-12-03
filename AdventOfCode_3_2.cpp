#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

unsigned long long getJoltage(string bank) {
    int bankLength = bank.length();
    int resultLength = bankLength;

    // Odstraò menšie èíslice z¾ava doprava, aby zostalo presne 12 èíslic
    for (int i = 0; i < bankLength && resultLength > 12; i++) {
        for (int j = 0; j < bankLength - 1 && resultLength > 12; j++) {
            if (bank[j] < bank[j + 1]) {
                bank[j] = 'n';   // oznaè na odstránenie
                resultLength--;
            }
        }
    }

    // Ak ešte stále viac ako 12, odstráò duplicitné alebo zbytoèné èíslice sprava
    for (int i = bankLength - 1; i >= 0 && resultLength > 12; i--) {
        if (bank[i] != 'n') {
            bank[i] = 'n';
            resultLength--;
        }
    }

    // Vytvor výsledok z nepovšimnutých èíslic
    string bankResult = "";
    for (char c : bank) {
        if (c != 'n')
            bankResult += c;
    }

    return stoull(bankResult);
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
