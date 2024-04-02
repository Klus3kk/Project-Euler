#include <iostream>
#include <vector>

using namespace std;

long long collatzSequenceLength(long long n, vector<int>& memo) {
    if (n < memo.size() && memo[n] != 0) {
        return memo[n];
    }

    long long length;
    if (n % 2 == 0) {
        length = 1 + collatzSequenceLength(n / 2, memo);
    } else {
        length = 2 + collatzSequenceLength((3 * n + 1) / 2, memo);  // 2 steps at once for optimization
    }

    if (n < memo.size()) {
        memo[n] = length;
    }
    return length;
}

int main() {
    int n = 1000000;
    vector<int> memo(n + 1, 0);
    memo[1] = 1;

    int max_length = 0;
    int max_i = 0;
    for (int i = 2; i <= n; i++) {
        int length = collatzSequenceLength(i, memo);
        if (length > max_length) {
            max_length = length;
            max_i = i;
        }
    }

    cout << "The number under " << n << " that produces the longest Collatz sequence is: " << max_i << endl;

    return 0;
}