// C++ Program to solve House Robber Problem using Recursion

#include <iostream>
#include <vector>
using namespace std;

// Calculate the maximum stolen value recursively
int maxLootRec(vector<int> &hval, int n) {
	
    // If no houses are left, return 0.
    if (n <= 0)  return 0;
  
  	// If only 1 house is left, rob it. 
    if (n == 1)  return hval[0];

    // Two Choices: Rob the nth house and do not rob the nth house 
    int pick = hval[n - 1] + maxLootRec(hval, n - 2);
    int notPick = maxLootRec(hval, n - 1);

    // Return the max of two choices
    return max(pick, notPick);
}

// Function to calculate the maximum stolen value
int maxLoot(vector<int>& hval) {
    int n = hval.size();
  
    // Call the recursive function for n houses
  	return maxLootRec(hval, n);
}

int main() {
    vector<int> hval = {6, 7, 1, 3, 8, 2, 4};
    cout << maxLoot(hval);
    return 0;
}
