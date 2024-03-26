#include <iostream>

int main() {
    int y = 1000;
    for (int a = 1; a <= y; a++) {
        for (int b = a + 1; b <= y; b++) {
            for (int c = b + 1; c <= y; c++) {
                if (a * a + b * b == c * c) {
                    if (a + b + c == y) {
                        std::cout << a << " " << b << " "<< c << " " << a*b*c << std::endl;
                        return 0;
                    }
                }
            }
        }
    }
    return 0;
}