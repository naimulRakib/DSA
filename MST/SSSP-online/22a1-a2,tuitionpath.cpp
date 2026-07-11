#include <iostream>
#include <algorithm>
using namespace std ; 
const int INF = 1e8;

int main (
)
{

    int penalty, nodes, vertices;
    cin >>penalty >>nodes>> vertices;

    vector <vector <vector<int > >> adj(nodes+1);

    vector <int> dist (nodes+1, INF);

    vector <int > parents(nodes+1, -1);

    priority_queue<vector <int >, vector <vector<int >>, greater<vector <int >>> pq;
  vector <int > timetaken(nodes+1,0);


    for (int i = 0; i<vertices; i++)
    {
        int u,v,t,c;
        cin >>u>>v>>t>>c;
adj[u].push_back({v,t,c});


    }
int s,d;
cin >>s>>d;

    pq.push({0,s ,0});
    dist[s]=0;



    while (!pq.empty())
    {
    auto pqnode= pq.top();
    pq.pop();

    int c=pqnode[0];
    int v= pqnode[1];
    int t= pqnode[2];


    for (auto neigh :adj[v])
    {
        int timenow = neigh[1]+t;
       
  int costnow= c+neigh[2]+penalty*timenow;


  if (neigh[0]!=s &&neigh[0]!=d)
  {
    timenow+=1;
    costnow+=penalty;

  }

  if (costnow < dist[neigh[0]])
  {
    dist[neigh[0]]=costnow;
     timetaken[neigh[0]]=timenow;
     parents[neigh[0]]=v;
    pq.push({costnow, neigh[0], timenow });
  }

  




        
    }

    }

    cout << dist[d]<< endl;



    
}