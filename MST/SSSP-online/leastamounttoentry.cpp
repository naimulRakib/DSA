#include <iostream>
#include <algorithm>
using namespace std;

const int INF= 1e8;
int main()
{

    int n, m ;
    cin >>n >> m ;
    vector <int > taxes(n+1);

    for (int i=1; i<=n; i++)
    {
        cin >>taxes[i];

    }

    vector <vector <pair <int , int >>>adj(n+1);

    for (int i=0;i <m; i++)
    {
        int u,v;
        cin >>u >>v;
        adj[u].push_back({v, taxes[v]});
        adj[v].push_back({u, taxes[u]});
    }
   


    priority_queue<pair <int, int>, vector <pair <int, int >>,  greater<pair <int , int >>> pq;
    vector <int > dist (n+1, INF);
    dist[1]=0;
    pq.push({0,1});


    while (!pq.empty())
    {
        auto edge = pq.top();
        pq.pop();
        int cost = edge.first;
        int curnode = edge.second;
      if (dist[curnode]< cost) continue; 

      for (auto e: adj[curnode])
      {
        int v = e.first;
        int w= e.second;

        if (dist[curnode]+w< dist[v])
        {
            dist[v]=dist[curnode]+w;
            pq.push({dist[v], v});


        }


      }

    }

    cout << dist[n]<< endl;

}