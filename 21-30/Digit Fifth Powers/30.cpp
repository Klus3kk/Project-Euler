#include <iostream>
#include <cmath>

bool isSumOfFifthPowers(int num) {
    int sum = 0, originalNum = num;
    while (num > 0) {
        int digit = num % 10;
        sum += std::pow(digit, 5);
        num /= 10;
    }
    return sum == originalNum;
}

int main() {
    int result = 0;
    
    for (int i = 2; i <= 354294; ++i) {
        if (isSumOfFifthPowers(i)) {
            result += i;
        }
    }

    std::cout << "The sum of all numbers that can be written as the sum of fifth powers of their digits is: " << result << std::endl;

    return 0;
}
