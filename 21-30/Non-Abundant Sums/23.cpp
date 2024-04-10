#include <iostream>
#include <vector>

int sumOfDivisors(int n) {
    int sum = 1; 
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            sum += i;
            if (i != n / i) sum += n / i; 
        }
    }
    return sum;
}

bool isAbundant(int n) {
    return sumOfDivisors(n) > n;
}

int main() {
    const int limit = 28123;
    std::vector<int> abundantNumbers;

    for (int i = 1; i <= limit; i++) {
        if (isAbundant(i)) {
            abundantNumbers.push_back(i);
        }
    }

    std::vector<bool> canBeWrittenAsAbundantSum(limit + 1, false);

    for (size_t i = 0; i < abundantNumbers.size(); i++) {
        for (size_t j = i; j < abundantNumbers.size(); j++) {
            int sum = abundantNumbers[i] + abundantNumbers[j];
            if (sum <= limit) {
                canBeWrittenAsAbundantSum[sum] = true;
            } else {
                break; 
            }
        }
    }

    int result = 0;
    for (int i = 1; i <= limit; i++) {
        if (!canBeWrittenAsAbundantSum[i]) {
            result += i;
        }
    }

    std::cout << "The sum of all positive integers which cannot be written as the sum of two abundant numbers is: " << result << std::endl;

    return 0;
}
