#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>
#include <functional>

using namespace std;

vector <vector<pair <int , int >>> adj;

vector <bool >visited; 

void dfs(int u)
{
    visited[ u] = true;

    for (auto &a: adj[u])
    {
if (!visited[a.first])
{dfs(a.first);
}
    }
    

}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n);
  visited.reserve(n);
  for (int i= 0 ; i< n; i++)
  {
    visited[i]= false ; 

  }

vector <array <int , 3>> edges ; 

    for (int i=0; i<m ; i++ )
    {
        int u,v,w;
        cin >> u >> v>> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
        edges.push_back({w,u,v});
    }


    sort(edges.begin(), edges.end(),[](const array<int ,3> & a, const array<int ,3> b){
        return a[2]> b[2];
    });
for (auto &e: edges)
{
    int u= e[1];
    int v= e[2];
    int w= e[0];
    for (int i=0 ; i< adj[u].size();i++)
    {
        if (adj[u][i].first==v && adj[u][i].second ==w)
        {
            adj[u].erase(adj[u].begin() +i);

        }
    }
     for (int i=0 ; i< adj[v].size();i++)
    {
        if (adj[v][i].first==u&& adj[v][i].second ==w)
        {
            adj[v].erase(adj[v].begin() +i);
            
        }
    }

    bool isconnected = true ;
dfs(0);
for (int i=0 ; i< n; i++)
{
    if (!visited[i])
    {
        isconnected = false;

    }
}
if (isconnected== false)
{
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
    
}


}

}