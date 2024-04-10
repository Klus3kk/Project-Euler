#include <iostream>
#include <vector>
#include <algorithm>

std::string findNthPermutation(const std::vector<char>& elements, int n) {
    int size = elements.size();
    std::vector<char> localElements(elements);
    std::string result = "";
    n -= 1; 
    
    for (int i = size - 1; i > 0; i--) {
        int factorial = 1;
        for (int j = 2; j <= i; j++) {
            factorial *= j;
        }
        
        int index = n / factorial;
        result += localElements[index];
        localElements.erase(localElements.begin() + index);
        n %= factorial;
    }
    
    result += localElements[0]; 
    return result;
}

int main() {
    std::vector<char> elements = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int n = 1000000;
    
    std::string nthPermutation = findNthPermutation(elements, n);
    std::cout << "The " << n << "th lexicographic permutation of the digits 0 through 9 is: " << nthPermutation << std::endl;
    
    return 0;
}
