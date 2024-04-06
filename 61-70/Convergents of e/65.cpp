#include <iostream>
#include <vector>

class BigInteger {
public:
    std::vector<int> digits;

    BigInteger(long long num = 0) {
        do {
            digits.push_back(num % 10);
            num /= 10;
        } while (num > 0);
        if (digits.empty()) {
            digits.push_back(0);
        }
    }

    BigInteger operator+(const BigInteger& other) const {
        BigInteger result;
        int carry = 0;
        for (size_t i = 0; i < digits.size() || i < other.digits.size() || carry; ++i) {
            if (i == result.digits.size()) {
                result.digits.push_back(0);
            }
            result.digits[i] = carry + (i < digits.size() ? digits[i] : 0) + (i < other.digits.size() ? other.digits[i] : 0);
            carry = result.digits[i] / 10;
            result.digits[i] %= 10;
        }
        return result;
    }

    BigInteger operator*(int other) const {
        BigInteger result;
        long long carry = 0;
        for (size_t i = 0; i < digits.size() || carry; ++i) {
            if (i == result.digits.size()) {
                result.digits.push_back(0);
            }
            carry += (i < digits.size() ? (long long)digits[i] * other : 0);
            result.digits[i] = carry % 10;
            carry /= 10;
        }
        return result;
    }

    int sumOfDigits() const {
        int sum = 0;
        for (int digit : digits) {
            sum += digit;
        }
        return sum;
    }
};

int main() {
    int limit = 100;
    std::vector<BigInteger> numerators = {BigInteger(1), BigInteger(2)}; 
    int k = 2;

    for (int i = 2; i <= limit; i++) {
        int c = (i % 3 == 0) ? 2 * (i / 3) : 1;
        BigInteger next = numerators[1] * c + numerators[0];
        numerators[0] = numerators[1];
        numerators[1] = next;
    }

    std::cout << "Sum of digits: " << numerators[1].sumOfDigits() << std::endl;

    return 0;
}
