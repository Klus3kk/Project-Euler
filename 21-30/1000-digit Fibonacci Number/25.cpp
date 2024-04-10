#include <iostream>
#include <vector>

int findFibonacciWithNDigits(int digits) {
    if (digits == 1) return 1;

    std::vector<int> a(1000, 0), b(1000, 0), c(1000, 0);
    a[0] = 1; 
    b[0] = 1; 
    int term = 2;

    while (b[digits - 1] == 0) {
        int carry = 0;
        for (int i = 0; i < 1000; ++i) {
            int sum = a[i] + b[i] + carry;
            c[i] = sum % 10;
            carry = sum / 10;
        }

        a = b;
        b = c;
        ++term;
    }

    return term;
}

int main() {
    int digits = 1000;
    int result = findFibonacciWithNDigits(digits);
    std::cout << "The first term in the Fibonacci sequence to have " << digits << " digits is: " << result << std::endl;
    return 0;
}
