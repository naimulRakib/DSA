#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;
vector<vector<pair<int, int>>> adj;

vector<array<int, 3>> edges;

vector<bool> visited;

vector <int >parent ;

int find(int x) {
    if (parent[x] == x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);

    if (rootx != rooty) {
        parent[rootx] = rooty;
        return true;
    } else
        return false;
}

void resetparent(int n) {
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}

void dfs(int u)
{
    visited[u]= true;

for (auto a: adj[u])
{
    if (!visited [a.first])
    {
        dfs(a.first);
    }
}
}

    int main()
{


    int n, m;
      cin >> n >> m;
    visited.resize(n);
   adj.resize(n);

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
   
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({w, u, v});

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
sort (edges.begin(), edges.end(),[](const array <int ,3> &a, const array<int , 3> &b){
    return a[0]> b[0];

}
);

resetparent(n);

int  deletedweight =0 ;

int totalweight=0;
    for (auto e : edges)

    {
        int w = e[0];
        int u = e[1];
        int v = e[2];
totalweight+=w;

        

        for (int i = 0; i < adj[u].size(); i++)
        {
            if (adj[u][i].first == v && adj[u][i].second == w)
            {
                adj[u].erase(adj[u].begin() + i);
                break;
            }

        

        }
        for (int i = 0; i < adj[v].size(); i++)
        {
            if (adj[v][i].first == u && adj[v][i].second == w)
            {
                adj[v].erase(adj[v].begin() + i);
                break;
            }
        }
for (int i=0 ; i<n ; i++)visited[i]= false;
        dfs(u);

bool isconnected = true ;
for (int i= 0; i< n; i++)
{
    if (!visited[i])
    {
        isconnected= false;
        break;
    }
}

if (!isconnected)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});



}
else {
    if (unite(u,v))
    {
        deletedweight+= w;
    }
   
}



    }

    cout << totalweight- deletedweight <<endl;
}