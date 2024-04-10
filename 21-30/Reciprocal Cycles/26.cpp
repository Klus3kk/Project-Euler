#include <iostream>
#include <vector>

int cycleLength(int n) {
    int remainder = 1;
    std::vector<int> seenRemainders(n, 0);
    int position = 0;

    while (seenRemainders[remainder] == 0 && remainder != 0) {
        seenRemainders[remainder] = position;
        remainder = remainder * 10 % n;
        position++;
    }

    return position - seenRemainders[remainder];
}

int main() {
    int maxLength = 0;
    int d = 0;

    for (int i = 2; i < 1000; i++) {
        int length = cycleLength(i);
        if (length > maxLength) {
            maxLength = length;
            d = i;
        }
    }

    std::cout << "The value of d < 1000 for which 1/d contains the longest recurring cycle is: " << d << std::endl;
    return 0;
}
