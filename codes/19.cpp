#include <bits/stdc++.h>
using namespace std;

// Function to perform Best First Search
vector<int> bestFirstSearch(vector<vector<int>> edges, 
        int src, int target, int n) {

    // create the adjacency list
    vector<vector<vector<int>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
    }

    // create a visited array to 
    // keep track of visited nodes
    vector<bool> visited(n, false);

    // create the min heap to store the nodes
    // based on the cost
    priority_queue<vector<int>, vector<vector<int>>, 
            greater<vector<int>>> pq;

    // push the source node in the min heap
    pq.push({0, src});

    // mark the source node as visited
    visited[src] = true;

    // to store the path   
    vector<int> path;

    // loop until the min heap is empty
    while (!pq.empty()) {

        // get the top element of the min heap
        int x = pq.top()[1];

        // push the current node in the path
        path.push_back(x);

        // pop the top element
        pq.pop();

        // if the current node is the target node
        // break the loop
        if (x == target)
            break;

        // loop through the edges of the current node
        for (int i = 0; i < adj[x].size(); i++) {

            // if the node is not visited
            if (!visited[adj[x][i][0]]) {

                // mark the node as visited
                visited[adj[x][i][0]] = true;

                // push the node in the min heap
                pq.push({adj[x][i][1], adj[x][i][0]});
            }
        }
    }

    return path;
}

int main() {
    int n = 14;
    vector<vector<int>> edgeList = {
        {0, 1, 3}, {0, 2, 6}, {0, 3, 5},
        {1, 4, 9}, {1, 5, 8}, {2, 6, 12},
        {2, 7, 14}, {3, 8, 7}, {8, 9, 5},
        {8, 10, 6}, {9, 11, 1}, {9, 12, 10},
        {9, 13, 2}
    };

    int source = 0;
    int target = 9;

    vector<int> path = bestFirstSearch(edgeList, source, target, n);

    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    return 0;
}
