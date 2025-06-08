#include <iostream>
#include <vector>
using namespace std;

// Build the LPS (Longest Prefix Suffix) array
vector<int> buildLPS(const string& pattern) {
    int m = pattern.size();
    vector<int> lps(m);
    int len = 0;
    lps[0] = 0; // first value is always 0

    int i = 1;
    while (i < m) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1]; // backtrack
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

// KMP Search Algorithm
void KMPsearch(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> lps = buildLPS(pattern);

    int i = 0, j = 0; // i -> text, j -> pattern
    while (i < n) {
        if (text[i] == pattern[j]) {
            i++; j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
            j = lps[j - 1]; // continue searching
        } else if (i < n && text[i] != pattern[j]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}
