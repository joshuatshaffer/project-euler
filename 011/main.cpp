//  Problem 11
//  Created by Joshua Shaffer on 2/8/16.
//  Copyright © 2016 Joshua Shaffer. All rights reserved.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

const string data_fname = "/Users/joshuashaffer/Desktop/Project Euler/xcode "
                          "prod/peworking/problem-011-data.txt";

int **load_data () {
    ifstream file (data_fname);

    int **nums = new int *[20];
    for (int i = 0; i < 20; ++i)
        nums[i] = new int[20];

    int n;
    for (int x = 0; x < 20; ++x) {
        for (int y = 0; y < 20; ++y) {
            file >> n;
            nums[x][y] = n;
        }
    }
    file.close ();
    return nums;
}

int main (int argc, const char *argv[]) {
    int **nums = load_data ();
    long max_prod = 0;

    for (int x = 3; x < 20; ++x) {
        for (int y = 0; y < 20; ++y) {
            cout << nums[x][y] << " ";
        }
        cout << endl;
    }
    // Horizontal
    for (int x = 3; x < 20; ++x) {
        for (int y = 0; y < 20; ++y) {
            long prod = 1;
            for (int i = 0; i < 4; ++i) {
                prod *= nums[x - i][y];
            }
            if (max_prod < prod) {
                max_prod = prod;
            }
        }
    }

    // Vertical
    for (int x = 0; x < 20; ++x) {
        for (int y = 3; y < 20; ++y) {
            long prod = 1;
            for (int i = 0; i < 4; ++i) {
                prod *= nums[x][y - i];
            }
            if (max_prod < prod) {
                max_prod = prod;
            }
        }
    }

    //
    for (int x = 3; x < 20; ++x) {
        for (int y = 3; y < 20; ++y) {
            long prod = 1;
            for (int i = 0; i < 4; ++i) {
                prod *= nums[x - i][y - i];
            }
            if (max_prod < prod) {
                max_prod = prod;
            }
        }
    }

    //
    for (int x = 3; x < 20; ++x) {
        for (int y = 3; y < 20; ++y) {
            long prod = 1;
            for (int i = 0; i < 4; ++i) {
                prod *= nums[x - (3 - i)][y - i];
            }
            if (max_prod < prod) {
                max_prod = prod;
            }
        }
    }

    cout << max_prod << endl;

    delete nums;
    return 0;
}
