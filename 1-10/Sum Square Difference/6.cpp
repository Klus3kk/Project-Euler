#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int sum =0, sumsqrt=0;
    for(int i = 1; i <= 100; i++) {
        sum += pow(i,2);
        sumsqrt += i;
    }
    sumsqrt = pow(sumsqrt,2);
    cout << (sumsqrt - sum) << endl;
    return 0;
}