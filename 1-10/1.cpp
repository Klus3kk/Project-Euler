#include <iostream>
#include <unordered_set>
using namespace std;
int sum = 0;
int main() {
    unordered_set<int> secik{};
    for(int i = 3; i < 1000; i += 3) {
        secik.insert(i);
    }
    for(int i = 5; i < 1000; i += 5) {
        secik.insert(i);
    }
    for(int y : secik) {
        sum += y;
    }
    cout << sum;
}
