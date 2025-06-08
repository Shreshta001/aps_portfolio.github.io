#include <iostream>
#include <vector>

using namespace std;

// Function to compute ways to reach n using steps from 1 to k
int countWays(int n, int k, vector<int>& dp) {
    if (n == 0) return 1;
    if (n < 0) return 0;

    if (dp[n] != -1) return dp[n];

    int ways = 0;
    for (int step = 1; step <= k; ++step) {
        ways += countWays(n - step, k, dp);
    }

    dp[n] = ways;
    return ways;
}

int main() {
    int n, k;
    cout << "Enter target number n: ";
    cin >> n;
    cout << "Enter max step size k: ";
    cin >> k;

    vector<int> dp(n + 1, -1);
    int result = countWays(n, k, dp);

    cout << "Total ways to reach " << n << ": " << result << endl;
    return 0;
}
