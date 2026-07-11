#include <iostream>
#include <algorithm>
using namespace std ; 
const int INF = 1e8;

int main (
)
{
    int n,m, k, b,e;
    cin >> n >> m >> k >> b >> e;

    vector <int > capitals (k);

    for (int i= 0 ; i< k; i++
    )
    {
        cin >> capitals[i];
    }

    vector <bool> isBlocked(n);
    for (int i=0; i < b; i++)
    {
        int u; 
        cin >>u;
        isBlocked[u]=true ; 

    }
    

    vector <int > emergencies(e);
    for (int i=0; i <e; i++)
    {
        cin >> emergencies[i];

    }
    vector <vector <pair<int,int>>> adj(n+1);
    for (int i=0 ; i< m ; i++)
    {
        int u,v,w; 
        cin >>u >> v>>w; 
         if (!isBlocked[u] && !isBlocked[v])
         {
            adj[u].push_back({v, w});

         }

    }

    for (int cap :capitals)
    {
        if (!isBlocked[cap])
        {
            adj[0].push_back({cap,0});

        }
    }

    vector<int > dist (n+1, INF);
    vector <int >count(n+1,0);
    vector<bool> inQueue(n+1, false)
    ;
   priority_queue<vector <int >, vector <vector <int >>, greater <vector <int >>>pq;


    dist[0]=0 ; 
    

 pq.push({0,0});

   inQueue[0]= true ;
   count[0]=1;


   bool abyssDetected = false;

   while (!pq.empty())
   {
    auto u =pq.top();
    int cost = u[0];
    int node = u[1];


    pq.pop();
    inQueue[node]=  false;

    for (auto edge: adj[node])
    {
        int v= edge.first;
        int w= edge.second; 
        if(dist[node]+w< dist[v])
        {
            dist[v]= dist[node]+w;
            pq.push({dist[v], v});
            inQueue[v]= true;
            count[v]++;

            if (count[v]> n )
            {
                abyssDetected= true; 
                break;

            }

        }


    }

    if (abyssDetected)
    {
        break;
    }

   }

   for (int target :emergencies)
   {
    cout<< dist[target ]<<" ";

   }
   cout << endl;

   if (abyssDetected)
   {
    cout << "IMPOSSIBLE"<< endl;
   }
   
    
}