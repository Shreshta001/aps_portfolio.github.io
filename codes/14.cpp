#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

// 1️⃣ Recursive (Exponential)
long long catalanRecursive(int n) {
    if (n <= 1) return 1;
    long long res = 0;
    for (int i = 0; i < n; ++i)
        res += catalanRecursive(i) * catalanRecursive(n - 1 - i);
    return res;
}

// 2️⃣ Memoized (Top-Down DP)
long long catalanMemo(int n, vector<long long>& dp) {
    if (n <= 1) return 1;
    if (dp[n] != -1) return dp[n];
    dp[n] = 0;
    for (int i = 0; i < n; ++i)
        dp[n] += catalanMemo(i, dp) * catalanMemo(n - 1 - i, dp);
    return dp[n];
}

// 3️⃣ Tabulation (Bottom-Up DP)
long long catalanDP(int n) {
    vector<long long> C(n + 1, 0);
    C[0] = C[1] = 1;
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            C[i] += C[j] * C[i - j - 1];
    return C[n];
}

// 4️⃣ Binomial Coefficient Method
long long binomialCoeff(int n, int k) {
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
    return res;
}

long long catalanBinomial(int n) {
    return binomialCoeff(2 * n, n) / (n + 1);
}

// 5️⃣ Modulo-safe Catalan for CP
long long modInverse(long long a, long long p) {
    long long res = 1;
    long long exp = p - 2;
    while (exp) {
        if (exp % 2) res = (res * a) % p;
        a = (a * a) % p;
        exp /= 2;
    }
    return res;
}

long long catalanMod(int n) {
    long long res = 1;
    for (int i = 0; i < n; ++i) {
        res = (res * (2 * n - i)) % MOD;
        res = (res * modInverse(i + 1, MOD)) % MOD;
    }
    res = (res * modInverse(n + 1, MOD)) % MOD;
    return res;
}

// 🚀 Driver
int main() {
    int n;
    cout << "Enter value of n: ";
    cin >> n;

    vector<long long> memo(n + 1, -1);

    cout << "\nCatalan(" << n << ") using:\n";
    cout << "🔁 Recursive        = " << catalanRecursive(n) << "\n";
    cout << "🧠 Memoized         = " << catalanMemo(n, memo) << "\n";
    cout << "📚 Tabulation DP    = " << catalanDP(n) << "\n";
    cout << "🧮 Binomial Formula = " << catalanBinomial(n) << "\n";
    cout << "⚔️ Modulo (CP)      = " << catalanMod(n) << " mod " << MOD << "\n";

    return 0;
}
