#include <iostream>
#include <vector>

using namespace std;

bool is_valid (int n) {
    for (int i=1; i<21; ++i)
        if (n % i != 0)
            return false;
    return true;
}

int main () {
    int n = 1;
    while (!is_valid(n)) ++n;
    cout << n << endl;
}