#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <ctime>

// Function to draw with replacement
void drawWithReplacement(const std::vector<std::string>& urn, int draws) {
    std::mt19937 rng(time(nullptr));
    std::uniform_int_distribution<int> dist(0, urn.size() - 1);

    std::cout << "Draws with Replacement:\n";
    for (int i = 0; i < draws; ++i) {
        std::string ball = urn[dist(rng)];
        std::cout << "Draw " << i + 1 << ": " << ball << "\n";
    }
    std::cout << "\n";
}

// Function to draw without replacement
void drawWithoutReplacement(const std::vector<std::string>& urn, int draws) {
    if (draws > urn.size()) {
        std::cout << "Cannot draw more than available items without replacement.\n";
        return;
    }

    std::mt19937 rng(time(nullptr));
    std::unordered_set<int> drawnIndices;

    std::cout << "Draws without Replacement:\n";
    int count = 0;
    while (count < draws) {
        int idx = rng() % urn.size();
        if (drawnIndices.find(idx) == drawnIndices.end()) {
            drawnIndices.insert(idx);
            std::cout << "Draw " << count + 1 << ": " << urn[idx] << "\n";
            count++;
        }
    }
    std::cout << "\n";
}

int main() {
    // Example: Urn with colored balls
    std::vector<std::string> urn = {"Red", "Blue", "Green", "Yellow", "Black"};

    int numberOfDraws = 3;

    drawWithReplacement(urn, numberOfDraws);
    drawWithoutReplacement(urn, numberOfDraws);

    return 0;
}
