#include <iostream>

using namespace std;

bool is_prime (long n) {
    if (n <= 3) {
        return n > 1;
    } else if (n % 2 == 0 || n % 3 == 0) {
        return false;
    } else {
        for (long i = 5; i * i <= n; i += 6) {
            if (n % i == 0 || n % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }
}

long lpf (long n) {
    long last_prime_factor = 0;
    long ns = n;
    for (long p = 2; p * p <= ns; ++p) {
        if (is_prime (p)) {
            while (n % p == 0) {
                n = n / p;
                last_prime_factor = p;
            }
        }
    }
    return last_prime_factor;
}

int main () {
    long n = 600851475143;
    cout << lpf (n) << endl;
}
