#include <iostream>
#include <vector>

using namespace std;

int main () {
    int sum_squares = 0;
    int square_sum = 0;

    for (int i = 1; i < 101; ++i) {
        sum_squares += i * i;
        square_sum += i;
    }
    square_sum *= square_sum;

    cout << (square_sum - sum_squares) << endl;
}
