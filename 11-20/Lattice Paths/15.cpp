#include <iostream>
#include <vector>
using namespace std;
// DP solution
int main() {
    int n = 20;
    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    // Initialize the top row and the left column to 1
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
        dp[0][i] = 1;
    }

    // Calculate the number of ways for each cell
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    cout << "The number of routes through a " << n << "x" << n << " grid is: " << dp[n][n] << endl;

    return 0;
}