#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int kadane(const vector<int>& arr) {
    int current_max = 0;
    int global_max = INT_MIN;

    for (int num : arr) {
        current_max += num;
        if (current_max > global_max)
            global_max = current_max;
        if (current_max < 0)
            current_max = 0;
    }
    return global_max;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter " << n << " elements (positive or negative):\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max_subarray_sum = kadane(arr);
    cout << "Maximum subarray sum is: " << max_subarray_sum << endl;

    return 0;
}
