// C++ program for solving 0/1 Knapsack Problem using
// recursion

#include <iostream>
#include <vector>
using namespace std;

// Recursive function to solve 0/1 Knapsack problem
int knapsackRecursive(vector<int>& weight,
                      vector<int>& value, int W, int n)
{
    // Base case: no items left or capacity is 0
    if (n == 0 || W == 0)
        return 0;

    // If weight of the nth item is more than knapsack
    // capacity W, it cannot be included
    if (weight[n - 1] > W)
        return knapsackRecursive(weight, value, W, n - 1);

    // Return the maximum of two cases: (1) nth item
    // included (2) not included
    return max(value[n - 1]
                   + knapsackRecursive(weight, value,
                                       W - weight[n - 1],
                                       n - 1),
               knapsackRecursive(weight, value, W, n - 1));
}

int main()
{
    // define a vector of weight
    vector<int> weight = { 1, 2, 4, 5 };

    // define a vector of value
    vector<int> value = { 5, 4, 8, 6 };

    // Knapsack capacity
    int W = 5;

    // call the recusrsive function and print the max value
    // obtained
    cout << "Maximum value = "
         << knapsackRecursive(weight, value, W,
                              weight.size())
         << endl;
    return 0;
}
