#include <iostream>
using namespace std;

int sum = 0, i = 0;

int fib(int n) {
    if(n==0) return 0;
    else if(n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    while(fib(i++) < 4000000) {
        if(fib(i) % 2 == 0) {
            sum += fib(i);
        }
    }
    cout << sum;
    return 0;
}