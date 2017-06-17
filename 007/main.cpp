//  Problem 7
//  Created by Joshua on 2/7/16.
//  Copyright © 2016 joshuatshaffer. All rights reserved.

#include <array>
#include <iostream>
using namespace std;

const int num_of_primes = 10001;

int main (int argc, const char *argv[]) {
    array<int, num_of_primes> primes;
    int current_index = 0;
    int n = 2;
    while (current_index < num_of_primes) {

        for (int i = 0; i < current_index; ++i) {
            if (n % primes[i] == 0) {
                goto next_n;
            }
        }

        primes[current_index++] = n;
    next_n:
        ++n;
    }

    cout << primes.back () << endl;
    return 0;
}
