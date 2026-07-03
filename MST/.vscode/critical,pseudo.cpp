#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// --- DSU Global Variables & Functions ---
vector<int> parent;
int components;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

bool unite_set(int a, int b) {
    int rootA = find_set(a);
    int rootB = find_set(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
        components--; // Keep track of disconnected groups
        return true;
    }
    return false;
}

void reset_dsu(int n) {
    parent.resize(n);
    components = n;
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}
// ----------------------------------------

int main() {
    int n, m;
    // Read number of nodes (cities) and edges (roads)
    if (!(cin >> n >> m)) return 0;

    // edges will store: {weight, u, v, original_id}
    vector<array<int, 4>> edges;

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v, i});
    }

    // 1. Sort edges. Since 'weight' is at index 0, this automatically 
    // sorts from lightest to heaviest without needing a custom sorting function.
    sort(edges.begin(), edges.end());

    // 2. Find the Base MST weight
    reset_dsu(n);
    int base_weight = 0;
    
    for (auto e : edges) {
        int w = e[0], u = e[1], v = e[2];
        if (unite_set(u, v)) {
            base_weight += w;
        }
    }

    vector<int> critical;
    vector<int> pseudo_critical;

    // 3. Test every single edge to see if it is Critical or Pseudo-Critical
    for (int i = 0; i < m; ++i) {
        int current_weight = edges[i][0];
        int current_u = edges[i][1];
        int current_v = edges[i][2];
        int original_id = edges[i][3];

        // --- TEST A: Is it Critical? (Ignore this edge) ---
        reset_dsu(n);
        int weight_ignore = 0;
        
        for (int j = 0; j < m; ++j) {
            if (i == j) continue; // 🚫 Skip the edge we are testing
            
            if (unite_set(edges[j][1], edges[j][2])) {
                weight_ignore += edges[j][0];
            }
        }

        // If the graph is broken OR it costs more without this edge, it is CRITICAL
        if (components > 1 || weight_ignore > base_weight) {
            critical.push_back(original_id);
        } 
        else {
            // --- TEST B: Is it Pseudo-Critical? (Force this edge) ---
            reset_dsu(n);
            
            // 🎯 Force the current edge to be included first!
            unite_set(current_u, current_v);
            int weight_force = current_weight;
            
            // Now build the rest of the tree normally
            for (int j = 0; j < m; ++j) {
                if (i == j) continue; // Already added it
                
                if (unite_set(edges[j][1], edges[j][2])) {
                    weight_force += edges[j][0];
                }
            }

            // If the tree still equals the optimal base weight, it's a valid backup!
            if (weight_force == base_weight) {
                pseudo_critical.push_back(original_id);
            }
        }
    }

    // 4. Output the results
    // Print Critical Edges
    cout << "Critical Edges: ";
    for (int id : critical) cout << id << " ";
    cout << "\n";

    // Print Pseudo-Critical Edges
    cout << "Pseudo-Critical Edges: ";
    for (int id : pseudo_critical) cout << id << " ";
    cout << "\n";

    return 0;
}