#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int n) {
    string numString = to_string(n);
    int len = numString.length();
    for (int i = 0; i < len / 2; ++i) {
        if (numString[i] != numString[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int largestPalindromeProduct() {
    int maxPalindrome = 0;
    for (int i = 100; i < 1000; ++i) {
        for (int j = 100; j < 1000; ++j) {
            int product = i * j;
            if (isPalindrome(product) && product > maxPalindrome) {
                maxPalindrome = product;
            }
        }
    }
    return maxPalindrome;
}

int main() {
    cout << largestPalindromeProduct() << endl;
    return 0;
}
