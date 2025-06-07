#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to find the longest common substring between two strings
string longestCommonSubstring(const string& s1, const string& s2) {
    int m = s1.length();
    int n = s2.length();

    // Create a DP table to store lengths of longest common suffixes
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int maxLen = 0;
    int endIndex = 0;  // Index of last character of LCS in s1

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];

                if (dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    endIndex = i;
                }
            }
        }
    }

    // Extract the longest common substring
    return s1.substr(endIndex - maxLen, maxLen);
}

// Demo usage with dictionary simulation
int main() {
    string input = "applw";  // Misspelled input
    vector<string> dictionary = {"apple", "apply", "ape", "angle"};

    string bestMatch = "";
    int maxLength = 0;

    for (const string& word : dictionary) {
        string lcs = longestCommonSubstring(input, word);
        if (lcs.length() > maxLength) {
            maxLength = lcs.length();
            bestMatch = word;
        }
    }

    cout << "Input: " << input << endl;
    cout << "Suggested correction: " << bestMatch << endl;

    return 0;
}
