//  Problem 12
//  Created by Joshua Shaffer on 2/8/16.
//  Copyright © 2016 Joshua Shaffer. All rights reserved.

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main (int argc, const char *argv[]) {
    long n, i, p;
    int f, z;
    for (i = 1;; ++i) {
        n = i * (i + 1) / 2;
        f = 1;
        for (p = 2; n != 1; ++p) {
            z = 0;
            while (n % p == 0) {
                n /= p;
                ++z;
            }
            f *= z + 1;
        }
        if (f > 500) {
            cout << (i * (i + 1) / 2) << " : " << f << endl;
            return 0;
        }
    }
    return 1;
}
