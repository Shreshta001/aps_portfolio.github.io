// A Naive recursive implementation of LCS problem
#include <bits/stdc++.h>
using namespace std;

// Returns length of LCS for s1[0..m-1], s2[0..n-1]
int lcsRec(string &s1, string &s2,int m,int n) {
    
    // Base case: If either string is empty, the length of LCS is 0
    if (m == 0 || n == 0)
        return 0;

    // If the last characters of both substrings match
    if (s1[m - 1] == s2[n - 1])
      
        // Include this character in LCS and recur for remaining substrings
        return 1 + lcsRec(s1, s2, m - 1, n - 1);

    else
        // If the last characters do not match
        // Recur for two cases:
        // 1. Exclude the last character of s1 
        // 2. Exclude the last character of s2 
        // Take the maximum of these two recursive calls
        return max(lcsRec(s1, s2, m, n - 1), lcsRec(s1, s2, m - 1, n));
}
int lcs(string &s1,string &s2){
    
    int m = s1.size(), n = s2.size();
    return lcsRec(s1,s2,m,n);
}

int main() {
    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int m = s1.size();
    int n = s2.size();

    cout << lcs(s1, s2) << endl;

    return 0;
}
