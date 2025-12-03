#include <iostream>
using namespace std;

bool NEGATIVE;

int getValue(string text) {
	string result = ""; NEGATIVE = false;
	
	for(char c : text) {
		if(isdigit(c)) {
			result += c;
		} else if(c == 'L') {
			NEGATIVE = true;
		}
	}
	
	return stoi(result);
}

int main() {
	int dial = 50, password = 0; string rotation;
	while(cin >> rotation) {
		
		getValue(rotation);
		
		for(int i=0; i < getValue(rotation); i++) {
			if(NEGATIVE) {
				dial--;
			} else {
				dial++;
			}
            
			if(dial < 0) {
				dial = 99;
			} else if(dial > 99) {
				dial = 0;
			}
			
			if(dial == 0) {
			    password++;
            }
		}
	}
	
	cout << password << endl;
	
	return 0;
}
