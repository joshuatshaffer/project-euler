//  Problem 13
//  Created by Joshua Shaffer on 2/8/16.
//  Copyright © 2016 Joshua Shaffer. All rights reserved.

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const string data_fname = "/Users/joshuashaffer/Desktop/Project Euler/xcode "
                          "prod/peworking/problem-013-data.txt";

int main (int argc, const char *argv[]) {
    long long sum{0};

    ifstream file (data_fname);
    string s;
    while (file >> s) {
        string::size_type start = s.find_first_not_of (' ');
        long long a = stoll (s.substr (start, start + 15).c_str ());
        sum += a;
    }
    file.close ();

    cout << sum << endl;
    return 0;
}
