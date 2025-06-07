#include <iostream>
#include <vector>
using namespace std;

int findUnique(const vector<int>& arr) {
    int result = 0;
    for (int num : arr) {
        result ^= num;  // XOR cancels out duplicates
    }
    return result;
}

int main() {
    vector<int> arr = {4, 1, 2, 1, 2, 4, 9};  // All appear twice except 9
    int unique = findUnique(arr);
    cout << "Unique element is: " << unique << endl;
    return 0;
}
