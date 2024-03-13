#include <iostream>
using namespace std;

int evenlyDivisible(int i) {
    for(int y = 2; y <= 20; y++) {
        if(i % y != 0) {
            return 0;
        } 
    }
    return 1;
}


int main() {
    for(int i = 1000; i < 1000000000; i++) {
        if(evenlyDivisible(i) == 1) cout << i << endl;
    }
    return 0;
}
