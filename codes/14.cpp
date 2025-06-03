#include <iostream>
#include <vector>
using namespace std;

// Function to compute nth Catalan number using Dynamic Programming
unsigned long long catalanDP(int n) {
    vector<unsigned long long> catalan(n + 1, 0);

    // Base case
    catalan[0] = 1;

    // Fill the table up to nth Catalan number
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            catalan[i] += catalan[j] * catalan[i - 1 - j];
        }
    }

    return catalan[n];
}

int main() {
    int n;
    cout << "Enter n (to compute nth Catalan number): ";
    cin >> n;

    cout << "Catalan Number C_" << n << " = " << catalanDP(n) << endl;

    return 0;
}
