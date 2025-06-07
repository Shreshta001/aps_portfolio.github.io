#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Direction constants
#define LEFT -1
#define RIGHT 1

// Structure to represent elements with direction
struct Element {
    int value;
    int dir; // -1 for LEFT, 1 for RIGHT
};

// Find the largest mobile element index
int getMobileIndex(const vector<Element>& perm) {
    int mobileIndex = -1;
    for (int i = 0; i < perm.size(); i++) {
        int neighbor = i + perm[i].dir;
        if (neighbor >= 0 && neighbor < perm.size()) {
            if (perm[i].value > perm[neighbor].value) {
                if (mobileIndex == -1 || perm[i].value > perm[mobileIndex].value)
                    mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}

// Print the current permutation
void printPerm(const vector<Element>& perm) {
    for (const auto& e : perm)
        cout << e.value << " ";
    cout << endl;
}

// Generate all permutations using Johnson–Trotter
void generatePermutations(int n) {
    vector<Element> perm(n);
    for (int i = 0; i < n; i++)
        perm[i] = { i + 1, LEFT }; // Initialize direction to LEFT

    printPerm(perm);

    while (true) {
        int mobileIndex = getMobileIndex(perm);
        if (mobileIndex == -1) break; // No more mobile elements

        int swapIndex = mobileIndex + perm[mobileIndex].dir;
        swap(perm[mobileIndex], perm[swapIndex]);

        // After swap, reverse direction of elements greater than moved one
        for (auto& e : perm) {
            if (e.value > perm[swapIndex].value)
                e.dir *= -1;
        }

        printPerm(perm);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements (n): ";
    cin >> n;

    cout << "\nJohnson–Trotter Permutations:\n";
    generatePermutations(n);

    return 0;
}
