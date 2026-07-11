#include <iostream>
#include <algorithm>
using namespace std;

const int INF= 1e8;

int getans (      vector <vector <pair <int , int >>>adj,int n, int livein, int dest, int m )

{


  
    vector <int > parent (n,-1);
     priority_queue<pair <int, int>, vector <pair <int, int >>,  greater<pair <int , int >>> pq;
    vector <int > dist (n, INF);
    dist[livein]=0;
    pq.push({0,livein});


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
          parent[v]= curnode;


        }


      }

    }

    vector<int > path;
    for (int i = dest; i!=-1 ;i = parent[i])
    {
        path.push_back(i);

    }

    reverse(path.begin(), path.end());
    for (int p: path)
    {
        cout << p << " ";
    }

    cout << dist[dest]<< endl;

}
int main()
{

    int n, m ;
    cin >>n >> m ;
    vector <vector <pair <int , int >>>adj(n);

     for (int i=0;i <m; i++)
    {
        int u,v,w;
        cin >>u >>v>> w;
       
        adj[u].push_back({v, w});
    }


    
   int livein;
cin >> livein;

int dest =1;
getans(adj,n,livein,dest,m);
getans(adj,n, dest, livein,m);

   

}