#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
#include <climits>

using namespace std;

// Pair of (cost, node)
typedef pair<int, int> pii;

// Graph as adjacency list: node -> vector of (neighbor, cost)
unordered_map<int, vector<pii>> graph;

// Uniform Cost Search
void uniformCostSearch(int start, int goal) {
    // Min-heap based on cost
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    // Distance from start to each node
    unordered_map<int, int> dist;

    for (auto& node : graph)
        dist[node.first] = INT_MAX;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (node == goal) {
            cout << "Reached goal " << goal << " with cost: " << cost << endl;
            return;
        }

        for (auto& neighbor : graph[node]) {
            int nextNode = neighbor.first;
            int edgeCost = neighbor.second;

            if (cost + edgeCost < dist[nextNode]) {
                dist[nextNode] = cost + edgeCost;
                pq.push({dist[nextNode], nextNode});
            }
        }
    }

    cout << "Goal not reachable." << endl;
}

int main() {
    // Sample graph
    graph[0] = {{1, 4}, {2, 1}};
    graph[1] = {{3, 1}};
    graph[2] = {{1, 2}, {3, 5}};
    graph[3] = {};

    int start = 0, goal = 3;
    uniformCostSearch(start, goal);

    return 0;
}
