#include <iostream>

int main() {
    const int size = 1001;
    long long sum = 1; 

    for (int n = 3; n <= size; n += 2) {
        sum += 4 * n * n - 6 * (n - 1);
    }

    std::cout << "The sum of the numbers on the diagonals in a " << size 
              << "x" << size << " spiral is: " << sum << std::endl;

    return 0;
}
