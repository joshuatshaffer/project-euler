//  Problem 8
//  Created by Joshua on 2/7/16.
//  Copyright © 2016 joshuatshaffer. All rights reserved.
#include <iostream>
using namespace std;

int main (int argc, const char *argv[]) {
    for (int a = 0; a < 1001; ++a) {
        for (int b = 0; b < 1001; ++b) {
            for (int c = 0; c < 1001; ++c) {
                if ((a < b && b < c) && (a * a + b * b == c * c) &&
                    (a + b + c == 1000)) {
                    cout << " a = " << a << endl;
                    cout << " b = " << b << endl;
                    cout << " c = " << c << endl;
                    cout << " abc = " << (a * b * c) << endl;
                    // return 0;
                }
            }
        }
    }
    return 0;
}
