#include <iostream>
#include <vector>

using namespace std;

vector<int> get_digits (int n, int radex = 10) {
    vector<int> digits;
    while (n > 0) {
        digits.push_back (n % radex);
        n /= radex;
    }
    return digits;
}

bool is_palindrome (int n) {
    vector<int> digits = get_digits (n);
    auto first = digits.begin ();
    auto last = digits.end () - 1;
    while (first < last) {
        if (*first != *last)
            return false;
        ++first;
        --last;
    }
    return true;
}

int largest_palindrome () {
    int largest_p = 0;
    for (int i = 999; i > 0; --i) {
        for (int j = i; j > 0; --j) {
            int p = i * j;
            if (is_palindrome (p))
                if (largest_p < p)
                    largest_p = p;
        }
    }
    return largest_p;
}

int main () {
    vector<int> digits = get_digits (9035);
    for (int i = 0; i < digits.size (); ++i)
        cout << digits[i];
    cout << endl;

    cout << largest_palindrome () << endl;
}
