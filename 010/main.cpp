//  Problem 10
//  Created by Joshua Shaffer on 2/8/16.
//  Copyright © 2016 Joshua Shaffer. All rights reserved.

#include <iostream>
using namespace std;

bool is_prime (long n) {
    if (n < 2) {
        return false;
    } else if (n > 3) {
        if ((n % 2 == 0) || (n % 3 == 0)) {
            return false;
        }
        for (long div = 5; div * div <= n; div += 6) {
            if ((n % div == 0) || (n % (div + 2) == 0)) {
                return false;
            }
        }
        return true;
    } else {
        return true;
    }
}

int main (int argc, const char *argv[]) {
    long long sum = 2;
    for (long i = 3; i < 2000000; i += 2) {
        if (is_prime (i)) {
            cout << i << endl;
            sum += i;
        }
    }
    cout << sum << endl;           // 143042032112
    cout << LONG_LONG_MAX << endl; // 143042032112
    return 0;
}
