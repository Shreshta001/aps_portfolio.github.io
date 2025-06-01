// C++ program to find number of ways
// to reach a given score in a game.
#include <bits/stdc++.h>
using namespace std;

int countRecur(int n, int i, vector<int> &points) {
    
    // Base cases
    if (n==0) return 1;
    if (n<0 || i==3) return 0;
    
    // take points[i] point 
    int take = countRecur(n-points[i], i, points);
    
    // skip point 
    int noTake = countRecur(n, i+1, points);
    
    return take + noTake;
}

int countWays(int n) {
    
    vector<int> points = {3, 5, 10};
    return countRecur(n, 0, points);
}

int main() {
    int n = 20;
    cout << countWays(n);
    return 0;
}
