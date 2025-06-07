// C++ program to demonstrate working of simple
// array query using iteration
#include <bits/stdc++.h>
using namespace std;

#define MAXN 10000

int arr[MAXN]; // original array

// Time Complexity: O(r-l+1)
int query(int l, int r)
{
    int sum = 0;
    for (int i = l; i <= r; i++) {
        sum += arr[i];
    }
    return sum;
}

// Driver code
int main()
{
    // We have used separate array for input because
    // the purpose of this code is to explain simple
    // array query using iteration in competitive
    // programming where we have multiple inputs.
    int input[] = { 1, 5, 2, 4, 6, 1, 3, 5, 7, 10 };
    int n = sizeof(input) / sizeof(input[0]);

    // copying input[] to arr[]
    memcpy(arr, input, sizeof(input));

    cout << "query(3,8) : " << query(3, 8) << endl;
    cout << "query(1,6) : " << query(1, 6) << endl;
    arr[8] = 0; // updating arr[8] to 0
    cout << "query(8,8) : " << query(8, 8) << endl;
    return 0;
}
