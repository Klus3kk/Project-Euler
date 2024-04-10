#include <iostream>
#include <cmath>
#include <vector>

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= std::sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int maxN = 0, maxA = 0, maxB = 0;

    for (int a = -999; a < 1000; ++a) {
        for (int b = -1000; b <= 1000; ++b) {
            int n = 0;
            while (isPrime(n * n + a * n + b)) {
                ++n;
            }
            if (n > maxN) {
                maxN = n;
                maxA = a;
                maxB = b;
            }
        }
    }

    std::cout << "The product of the coefficients, a and b, that produce the maximum number of consecutive primes is: " << maxA * maxB << std::endl;

    return 0;
}
