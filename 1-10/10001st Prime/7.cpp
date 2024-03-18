#include <iostream>
#include <string.h>
using namespace std;

void eratostenes(int n) {
    bool t[n+1];
    int c = 0,k = 0;
    memset(t, 1, sizeof(t));
    for(int i = 2; i * i <= n; i++) {
        if(t[i] == 1) {
            for(int j = i * 2; j <= n; j += i) {
                t[j] = 0;
            }
        }
    }
    while(c <= 10002) {
        if(t[k]) {
            cout << k << "\n";
            c++;
        }
        k++;
    }
}

int main() {
    int n = 1000000;
    eratostenes(n);
    return 0;
}