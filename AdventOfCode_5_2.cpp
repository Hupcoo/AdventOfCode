#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>


using namespace std;

int main() {
	vector<pair<unsigned long long, unsigned long long>> ranges;
	
	ifstream file("day5.txt");
    string temp;
    while (getline(file, temp)) {
        if (temp == "") break;
        int pos = temp.find('-');
        unsigned long long first = stoull(temp.substr(0, pos));
        unsigned long long second = stoull(temp.substr(pos + 1));
        ranges.push_back({first, second});
    }
    
    sort(ranges.begin(), ranges.end());
    
    unsigned long long rangeLeft = ranges[0].first,
                       rangeRight = ranges[0].second,
                       total = 0;
    
    for(int i=0; i<ranges.size(); i++) {
        unsigned long long left = ranges[i].first,
                           right = ranges[i].second;
        
        if(left <= rangeRight + 1) {
            rangeRight = max(rangeRight, right);
        } else {
            total += (rangeRight - rangeLeft + 1);
            rangeLeft = left;
            rangeRight = right;
        }
    }
    
    total += (rangeRight - rangeLeft + 1);
    cout << total << endl;
    
    
    return 0;
}
