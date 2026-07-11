#include <iostream>
#include <algorithm>
#include <queue>
using namespace std ; 
const int INF = 1e8;
// shortest path faster algorithm 
int main ()
{
    int n , m ;

cin >> n >> m ; 

vector <vector <vector <int > >> adj (n+1);


for (int i = 0 ; i<m ; i++)
{
    int u,v,w;
    cin >> u >> v >> w;
    adj[u].push_back({v,w});

}


vector <int > dist (n+1,0);
vector <int > parent(n+1, -1);
vector <bool> inQueue(n+1, true);
vector <int > count (n+1,1);
queue<int >q;
for (int i = 1; i <= n ; i++)
{

    q.push(i);
}




int cornode=-1;


while (!q.empty())
{
    int u = q.front();
    q.pop();
    inQueue[u]= false;

    for (auto edge: adj[u])
    {
        int node = edge[0];
        int cost = edge[1];


        if (dist[u]+cost < dist[node])
        {
            dist[node]= dist[u]+cost;
             parent[node]=u;

             if (!inQueue[node])
           { q.push(node);
            inQueue[node]= true;
            count[node]++;
             if (count[node]>=n)
        {
            cornode= node;
            cout << "found"<<"\n";
            break;

        }
           

        }

       
    }

    }
    if (cornode!=-1)
    {
        break;

    }


}
int curr= cornode;
for (int i = 0; i<=n ; i++)
{
    curr=parent[curr];

}

int start = curr;
vector<int >path ;
path.push_back(start);


for (int i=parent [curr];i!=start; i=parent[i] )
{
  path.push_back(i);
}
path.push_back(start);
reverse(path.begin(), path.end());
for (int p: path)
{
    cout<<p<<" ";
    
}


}