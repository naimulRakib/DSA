#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// --- DSU Global Variables & Functions ---
vector<int> parent;
int components;

int find_set(int v)
{
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]); // Path compression
}

bool unite_set(int a, int b)
{
    int rootA = find_set(a);
    int rootB = find_set(b);
    if (rootA != rootB)
    {
        parent[rootB] = rootA;
        components--; // Keep track of disconnected groups
        return true;
    }
    return false;
}

void reset_dsu(int n)
{
    parent.resize(n);
    components = n;
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
}

vector<array<int, 3>> edges;

void sortindescending()
{
    sort(edges.begin(), edges.end(), [](const array<int, 4> &a, const array<int, 4> &b)
         { return a[0] > b[0]; }

    );
}


vector <bool > visited;
vector <vector<pair<int , int >>> adj;

void dfs(int u)
{
    visited[u] = true;

    for (auto a : adj[u])
    {
        if (!visited[a.first])
        {
            dfs(a.first);
        }
    }
}
