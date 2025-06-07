#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int N = 1e5; // Max number of nodes
vector<int> adj[N]; // Adjacency list
bool visited[N];    // Visited array for both DFS and BFS

// -----------------------------
// 🔍 DFS - Depth First Search
// -----------------------------
void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

// -----------------------------
// 🌊 BFS - Breadth First Search
// -----------------------------
void bfs(int start) {
    queue<int> q;
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

// -----------------------------
// 🛠️ Main function
// -----------------------------
int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;

    cout << "Enter " << edges << " edges (u v):" << endl;
    for (int i = 0; i < edges; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // remove this line for directed graph
    }

    cout << "\nDFS Traversal starting from node 0: ";
    dfs(0);

    // Reset visited array for BFS
    fill(visited, visited + nodes, false);

    cout << "\nBFS Traversal starting from node 0: ";
    bfs(0);

    return 0;
}
