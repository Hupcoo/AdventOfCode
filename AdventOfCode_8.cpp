#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main() {
    vector<string> rows;
    ifstream fin("day8.txt");
    string temp;
    while(fin >> temp) 
		rows.push_back(temp);

    

    return 0;
}

