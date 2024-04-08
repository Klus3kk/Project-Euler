#include <iostream>
#include <vector>

int sumOfDivisors(int num) {
    int sum = 1; 
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            sum += i;
            if (i != num / i) {
                sum += num / i;
            }
        }
    }
    return sum;
}

int main() {
    const int limit = 10000; 
    int totalSum = 0;
    std::vector<bool> visited(limit, false);

    for (int a = 2; a < limit; a++) {
        if (!visited[a]) {
            int b = sumOfDivisors(a);
            if (b != a && sumOfDivisors(b) == a) {
                totalSum += a + b;
                visited[a] = visited[b] = true;
            }
        }
    }

    std::cout << "Sum of all the amicable numbers under " << limit << " is: " << totalSum << std::endl;

    return 0;
}
