#include <iostream>
#include <algorithm>
using namespace std ; 
const int INF = 1e8;

int main()
{
int n, m ,f;
cin >> n>> m>> f;
vector <int > capacity (n+1);
for (int i=1; i<=n; i++)
{
    cin >> capacity[i];
}

vector <vector <pair <int , int >>>  adj(n+1);
for (int i=0; i<m; i++)
{
    int u,v ,w; 
    cin >> u >> v>>w;
    adj[u].push_back({v,w});
     adj[v].push_back({u,w});


}

int k;
cin >> k ; 


vector <int >dist(n+1, INF);



    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1]=0;
    pq.push({0,1});
    while (!pq.empty())
    {
        int curdist = pq.top().first;
        int curnode= pq.top().second;
        pq.pop();
        if (curdist>dist[curnode]) continue;
        for (auto edge :adj[curnode])
        {
            int v= edge.first;
            int weight = edge.second;
            if (dist[curnode]+weight < dist[v])
            {
                dist[v]= dist[curnode]+weight ; 
                 pq.push({dist[v], v});

            }
           

        }

        
    }
vector <int > allseats;

    for (int i = 1; i<= n;i++)
    {
        if (dist[i]!= INF)
        {
            int totalcost = dist[i]+f;

            for (int j=0 ; j< capacity[i]; j++)
            {
                allseats.push_back(totalcost);
            }

        }
    }

sort(allseats.begin(), allseats.end());


    for (int i= 0 ; i < k ;i ++)
    {
        if (i<allseats.size())
        {
            cout << allseats[i]<< " ";

        }
        else 
        {
            cout << "-1";
        }
    }

    cout <<endl;


}