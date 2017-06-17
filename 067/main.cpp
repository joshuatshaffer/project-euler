//  Problem 67
//  Created by Joshua Shaffer on 2/9/16.
//  Copyright © 2016 Joshua Shaffer. All rights reserved.

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

const string datafname = "/Users/joshuashaffer/Desktop/Project Euler/xcode "
                         "prod/peworking/problem-067-data.txt";

vector<vector<int>> load_data () {
    vector<vector<int>> v;

    ifstream file{datafname};
    string line;
    int n;
    while (getline (file, line)) {
        stringstream stream (line);
        v.push_back (vector<int> ());
        while (stream >> n) {
            v.back ().push_back (n);
        }
        v.back ().shrink_to_fit ();
    }
    v.shrink_to_fit ();
    return v;
}

void print (vector<vector<int>> &v) {
    for (int i = 0; i < v.size (); ++i) {
        for (int j = 0; j < v[i].size (); ++j) {
            cout << setw (2) << setfill ('0') << v[i][j] << ' ';
        }
        cout << endl;
    }
}

int main (int argc, const char *argv[]) {
    vector<vector<int>> v = load_data ();

    print (v);

    for (int i = v.size () - 2; i >= 0; --i) {
        for (int j = 0; j < v[i].size (); ++j) {
            v[i][j] += max (v[i + 1][j], v[i + 1][j + 1]);
        }
    }
    cout << v[0][0] << endl;
}
