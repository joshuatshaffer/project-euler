//  Problem 14
//  Created by Joshua Shaffer on 2/8/16.
//  Copyright © 2016 Joshua Shaffer. All rights reserved.

#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {
    long n = 50, ms;
    int c, ml = 0;
    for (long i=999999; i>5; --i) {
        n = i;
        c = 0;
        while (n != 1) {
            ++c;
            if (n & 1) {
                n = 3*n + 1;
            } else {
                n >>= 1;
            }
        }
        if (ml < c) {
            ml = c;
            ms = i;
        }
    }
    cout << ms << endl;
    return 0;
}
