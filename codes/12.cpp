#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void printVector(const vector<int>& v) {
    for (int val : v) cout << val << " ";
    cout << endl;
}

double getMean(const vector<int>& nums) {
    double sum = 0;
    for (int n : nums) sum += n;
    return sum / nums.size();
}

double getMedian(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();
    if (n % 2 == 0)
        return (nums[n/2 - 1] + nums[n/2]) / 2.0;
    else
        return nums[n/2];
}

vector<int> getMode(const vector<int>& nums) {
    unordered_map<int, int> freq;
    int maxFreq = 0;

    for (int n : nums) {
        freq[n]++;
        maxFreq = max(maxFreq, freq[n]);
    }

    vector<int> mode;
    for (auto& [num, count] : freq)
        if (count == maxFreq)
            mode.push_back(num);

    // Handle uniform distribution (no mode)
    if (mode.size() == freq.size()) mode.clear();
    return mode;
}

void analyzeSkewness(double mean, double median) {
    if (mean == median)
        cout << "✅ Distribution: Symmetric (Normal)" << endl;
    else if (mean > median)
        cout << "↗️ Distribution: Right-skewed (Tail on right)" << endl;
    else
        cout << "↘️ Distribution: Left-skewed (Tail on left)" << endl;
}

int main() {
    vector<int> data = {1, 2, 2, 3, 4, 5, 6, 7};  // You can change this

    cout << "Input Data: ";
    printVector(data);

    double mean = getMean(data);
    double median = getMedian(data);
    vector<int> mode = getMode(data);

    cout << "📌 Mean: " << mean << endl;
    cout << "📌 Median: " << median << endl;
    
    cout << "📌 Mode: ";
    if (mode.empty())
        cout << "No mode (all frequencies equal)" << endl;
    else
        printVector(mode);

    analyzeSkewness(mean, median);

    return 0;
}
