#include <iostream>
#include <cmath>
using namespace std;

long long largestPrimeFactor(long long n) {
    long long maxPrime = 0;

    while (n % 2 == 0) {
        maxPrime = 2;
        n /= 2;
    }

    while (n % 3 == 0) {
        maxPrime = 3;
        n /= 3;
    }

    for (int i = 5; i <= sqrt(n); i += 6) {
        while (n % i == 0) {
            maxPrime = i;
            n = n / i;
        }
        while (n % (i + 2) == 0) {
            maxPrime = i + 2;
            n = n / (i + 2);
        }
    }

    // If n is still greater than 1, it's a prime number
    if (n > 1)
        maxPrime = n;

    return maxPrime;
}

int main() {
    cout << largestPrimeFactor(600851475143);
    return 0;
}
