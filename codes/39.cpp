#include <iostream>
#include <vector>
#include <random>
#include <map>
#include <algorithm>
#include <ctime>

using namespace std;

// Function to simulate drawing with replacement
void drawWithReplacement(const vector<string>& urn, int draws) {
    map<string, int> count;
    mt19937 rng(time(0)); // Random number generator
    uniform_int_distribution<int> dist(0, urn.size() - 1);

    for (int i = 0; i < draws; ++i) {
        string ball = urn[dist(rng)];
        count[ball]++;
    }

    cout << "\n🎲 Results (With Replacement):\n";
    for (auto& entry : count) {
        cout << entry.first << ": " << entry.second << " times\n";
    }
}

// Function to simulate drawing without replacement
void drawWithoutReplacement(vector<string> urn, int draws) {
    map<string, int> count;
    mt19937 rng(time(0));
    shuffle(urn.begin(), urn.end(), rng);

    cout << "\n🎯 Drawing without replacement:\n";
    for (int i = 0; i < min(draws, (int)urn.size()); ++i) {
        string ball = urn[i];
        count[ball]++;
        cout << "Draw " << i + 1 << ": " << ball << "\n";
    }
}

int main() {
    // Initial urn setup
    vector<string> urn = {
        "Red", "Red", "Blue", "Green", "Green", "Green", "Yellow"
    };

    int draws = 5;

    cout << "🎱 Urn contains:\n";
    for (auto& ball : urn) {
        cout << ball << " ";
    }
    cout << "\n\nNumber of draws: " << draws << "\n";

    drawWithReplacement(urn, draws);
    drawWithoutReplacement(urn, draws);

    return 0;
}
