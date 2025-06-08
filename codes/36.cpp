#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

void dfsWithPriority(int start, const vector<vector<int>>& adj) {
    vector<bool> visited(adj.size(), false);
    stack<int> s;

    s.push(start);

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        cout << node << " ";

        // Use a max-heap to process higher priority nodes first
        priority_queue<int> pq;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                pq.push(neighbor);
            }
        }

        while (!pq.empty()) {
            s.push(pq.top());
            pq.pop();
        }
    }
}

int main() {
    int n = 6;  // number of nodes
    vector<vector<int>> adj(n);

    // Sample undirected graph
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    int startNode = 0;
    cout << "DFS with Priority from node " << startNode << ": ";
    dfsWithPriority(startNode, adj);

    return 0;
}
