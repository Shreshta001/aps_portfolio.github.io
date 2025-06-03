#include <iostream>
#include <vector>
using namespace std;

// Function to generate Pascal's Triangle up to 'n' rows
vector<vector<int>> generatePascalsTriangle(int n) {
    vector<vector<int>> triangle(n);
    
    for (int i = 0; i < n; i++) {
        triangle[i].resize(i + 1);  // Each row has (i+1) elements
        triangle[i][0] = triangle[i][i] = 1;  // First and last elements are 1
        
        for (int j = 1; j < i; j++) {
            // Internal values are sum of two values from the previous row
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle;
}

int main() {
    int n;
    cout << "Enter number of rows for Pascal's Triangle: ";
    cin >> n;

    vector<vector<int>> triangle = generatePascalsTriangle(n);

    cout << "\nPascal's Triangle:\n";
    for (const auto& row : triangle) {
        for (int num : row)
            cout << num << " ";
        cout << "\n";
    }

    return 0;
}
