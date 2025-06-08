#include <bits/stdc++.h>
using namespace std;

int maxSumRectangle(vector<vector<int>> &mat) {
  
    int n = mat.size();
    int m = mat[0].size();
    int maxSum = INT_MIN;

    for (int up = 0; up < n; up++) {
        for (int left = 0; left < m; left++) {
            for (int down = up; down < n; down++) {
                for (int right = left; right < m; right++) {
                    
                    // Find the sum of submatrix(up, right, down, left)
                    int sum = 0;
                    for (int i = up; i <= down; i++) {
                        for (int j = left; j <= right; j++) {
                            sum += mat[i][j];
                        }
                    }

                    // Update maxSum if sum > maxSum.
                    if (sum > maxSum) {
                        maxSum = sum;
                    }
                }
            }
        }
    }

    return maxSum;
}
int main() {
    vector<vector<int>> mat = {{1, 2, -1, -4, -20}, 
                               {-8, -3, 4, 2, 1}, 
                               {3, 8, 10, 1, 3}, 
                               {-4, -1, 1, 7, -6}};
                               
    cout <<maxSumRectangle(mat) << endl;
    return 0;
}
