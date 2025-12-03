#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <unordered_map>

using namespace std;

bool isInvalid(string id) {
    int idLength = id.length();
    
    for(int len = 1; len <= idLength / 2; len++) {
        if(idLength % len != 0) 
            continue;
            
        string pattern = id.substr(0, len);
        bool allMatching = true;
        
        for(int i=0; i < idLength; i += len) {
            if(id.substr(i, len) != pattern) {
                allMatching = false;
                break;
            }
        }
        if(allMatching)
            return true;
    }
    return false;
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
			if(isInvalid(to_string(id_instance))) {
				invalid += id_instance;
			}
		}
	}
	
	cout << invalid << endl;
	
	return 0;
}
