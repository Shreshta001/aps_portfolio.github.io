#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int N = 1e5;             // Max size of array
const int K = 20;              // log2(N) upper bound
int st[N][K];                  // Sparse Table
int logTable[N + 1];           // Lookup table for logs

// Preprocessing the log values
void buildLogTable(int n) {
    logTable[1] = 0;
    for (int i = 2; i <= n; i++)
        logTable[i] = logTable[i / 2] + 1;
}

// Build sparse table for RMQ (min query)
void buildSparseTable(const vector<int>& arr) {
    int n = arr.size();
    buildLogTable(n);

    // Initialize the first level (k = 0)
    for (int i = 0; i < n; i++)
        st[i][0] = arr[i];

    // Build for higher levels
    for (int j = 1; (1 << j) <= n; j++) {
        for (int i = 0; i + (1 << j) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

// Query: RMQ from L to R in O(1)
int query(int L, int R) {
    int j = logTable[R - L + 1];
    return min(st[L][j], st[R - (1 << j) + 1][j]);
}

// Driver code
int main() {
    vector<int> arr = {1, 3, -1, 7, 0, 4, 2};
    int n = arr.size();

    buildSparseTable(arr);

    // Sample queries
    cout << "Min from 1 to 4: " << query(1, 4) << endl;  // Output: -1
    cout << "Min from 2 to 5: " << query(2, 5) << endl;  // Output: 0
    cout << "Min from 3 to 6: " << query(3, 6) << endl;  // Output: 0

    return 0;
}

