#include <iostream>
#include <vector>

void multiply(std::vector<int>& number, int n) {
    int carry = 0;
    for (size_t i = 0; i < number.size(); i++) {
        int product = number[i] * n + carry;
        number[i] = product % 10; 
        carry = product / 10; 
    }
    while (carry) { 
        number.push_back(carry % 10);
        carry /= 10;
    }
}

void factorial(std::vector<int>& number, int n) {
    number.push_back(1);
    for (int i = 2; i <= n; i++) {
        multiply(number, i);
    }
}

int digitSum(const std::vector<int>& number) {
    int sum = 0;
    for (int digit : number) {
        sum += digit;
    }
    return sum;
}

int main() {
    std::vector<int> number; 
    factorial(number, 100); 
    std::cout << "Sum of the digits in the number 100!: " << digitSum(number) << std::endl;
    return 0;
}
