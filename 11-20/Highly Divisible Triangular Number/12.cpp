#include <iostream>
#include <cmath>

using namespace std;

int countDivisors(int n) {
    int count = 0;
    int sqrtN = sqrt(n);
    for (int i = 1; i <= sqrtN; i++) {
        if (n % i == 0) {
            if (n / i == i) {
                count++;
            } else {
                count += 2;
            }
        }
    }
    return count;
}

int main() {
    int n = 1;
    int num = 1;
    while (true) {
        if (countDivisors(num) > 500) {
            cout << "The first triangle number to have over 500 divisors is: " << num << endl;
            break;
        }
        n++;
        num += n;
    }
    return 0;
}