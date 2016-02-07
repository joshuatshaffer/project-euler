//  Problem 8
//  Created by Joshua on 2/7/16.
//  Copyright © 2016 joshuatshaffer. All rights reserved.
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string fname = "/Users/joshua2/Desktop/lkhjlh.txt";
const int kernal_size = 13;

vector<int> load_file () {
    ifstream file (fname);
    char c;
    vector<int> digits;
    while (file >> c) {
        int d{c - '0'};
        if (0 <= d && d <= 9)
            digits.push_back(d);
    }
    return digits;
}

int main(int argc, const char * argv[]) {
    const vector<int> digits{load_file ()};
    
    long max_prod = -983568758467;
    for (int i=kernal_size-1; i<digits.size(); ++i) {
        long prod = 1;
        for (int j=0; j<kernal_size; ++j) {
            prod *= digits[i-j];
        }
        if (max_prod < prod) {
            max_prod = prod;
        }
    }
    cout << max_prod << endl;
    
    return 0;
}
