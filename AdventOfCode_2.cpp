#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

bool isValid(string number) {
	string left = number.substr(0, number.length() / 2);
	string right = number.substr(number.length() / 2);
	
	return left != right;
}

int main() {
	string ids_all = "";
	
	ifstream fin("day2.txt");
	string temp;
	while(fin >> temp) {
		ids_all += temp;
	}
	
	vector<string> ids;
	
	int start = 0;
	for(int i=0; i < ids_all.length(); i++) {
		if(ids_all[i] == ',') {
			ids.push_back(ids_all.substr(start, i - start));
			start = i+1;
		}
	}
    ids.push_back(ids_all.substr(start));
    
	unsigned long long invalid = 0;
	for(string id : ids) {		
		unsigned long long firstNum = stoull(id.substr(0, id.find('-'))),
						   secondNum = stoull(id.substr(id.find('-') + 1, id.length()));
		
		for(unsigned long long id_instance = firstNum; id_instance <= secondNum; id_instance++) {
			if(!isValid(to_string(id_instance))) {
				invalid += id_instance;
			}
		}
	}
	
	cout << invalid << endl;
	
	return 0;
}
