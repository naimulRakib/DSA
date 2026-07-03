#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <queue>

using namespace std;

// --- DSU Setup without Structs ---
vector<int> parent;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

bool unite_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        parent[b] = a;
        return true;
    }
    return false;
}

void reset_dsu(int n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}
// ---------------------------------

int main() {
    int n, m;
    // Read number of nodes and edges
    if (!(cin >> n >> m)) return 0;

    // Store edges as {weight, u, v}
    vector<array<int, 3>> edges;
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // Assuming 0-indexed nodes
        edges.push_back({w, u, v}); 
    }

    int start_city, end_city;
    cin >> start_city >> end_city;

    // 1. Sort edges (Automatically sorts by the first element: weight)
    sort(edges.begin(), edges.end());

    // 2. Build the MST
    reset_dsu(n);
    
    // Adjacency list for the MST: stores {neighbor, edge_weight}
    vector<vector<array<int, 2>>> mst_adj(n);

    for (auto e : edges) {
        int w = e[0], u = e[1], v = e[2];
        
        if (unite_set(u, v)) {
            // Only keep the successful MST edges
            mst_adj[u].push_back({v, w});
            mst_adj[v].push_back({u, w});
        }
    }

    // Edge case: If the two cities are completely disconnected
    if (find_set(start_city) != find_set(end_city)) {
        cout << "-1" << endl; 
        return 0;
    }

    // 3. Find the Minimax path using BFS on the MST
    // Queue stores {current_node, maximum_hazard_so_far}
    queue<array<int, 2>> q;
    vector<bool> visited(n, false);

    q.push({start_city, 0});
    visited[start_city] = true;

    int minimax_result = 0;

    while (!q.empty()) {
        auto current = q.front();
        int curr_node = current[0];
        int max_hazard_so_far = current[1];
        q.pop();

        // Because it's a tree, there's only one path. Once we hit the end, we are done!
        if (curr_node == end_city) {
            minimax_result = max_hazard_so_far;
            break;
        }

        for (auto neighbor : mst_adj[curr_node]) {
            int next_node = neighbor[0];
            int edge_weight = neighbor[1];

            if (!visited[next_node]) {
                visited[next_node] = true;
                // The new bottleneck is whichever is worse: 
                // the hazard so far, or the edge we are crossing right now
                q.push({next_node, max(max_hazard_so_far, edge_weight)});
            }
        }
    }

    // 4. Output the result
    cout << minimax_result << endl;

    return 0;
}