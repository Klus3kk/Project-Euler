#include <iostream>
#include <cstring>
using namespace std;

int SieveOfEratosthenes(int n)
{
    int sum = 0;   
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++)
        if (prime[p])
            sum += p;
    return sum;
}
 
// Driver Code
int main()
{
    int n = 2000000;
    cout << SieveOfEratosthenes(n);
    return 0;
}