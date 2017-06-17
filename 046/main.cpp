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

int next_prime (int n) {
    if (++n % 2 == 0)
        ++n;
    while (!is_prime (n))
        n += 2;
    return n;
}

bool goldbach (int n) {
    if (n % 2 == 0)
        return true;
    if (is_prime (n))
        return true;
    for (int i = 2; i < n; i = next_prime (i)) {
        int j = 1;
        while (j * j * 2 + i < n)
            ++j;
        if (j * j * 2 + i == n)
            return true;
    }
    return false;
}

int main () {
    int n = 9;
    while (goldbach (n))
        n += 2;
    cout << n << endl;
}
