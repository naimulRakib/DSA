#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
using namespace std;

const int INF= 1e8;
int main()
{

    int r1, r1m, r2, r2m;
    cin >> r1>> r1m>> r2>> r2m ;
map<string, int> name_to_id;
    map<int, string> id_to_name;

    int current_id=1;

auto getId = [&](string s) {
        if (name_to_id.find(s) == name_to_id.end()) {
            name_to_id[s] = current_id;
            id_to_name[current_id] = s;
            current_id++;
        }
        return name_to_id[s];
    };

    vector <vector <pair <int , int >>> adj(10000000);
    for (int i= 0 ; i< r1m; i++)
    {
        string s1, s2;
        int cost;
        cin >> s1>> s2;
        cin >> cost;

        int u= getId(s1);
        int v = getId(s2);
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});

    }
        for (int i= 0 ; i< r2m; i++)
    {
        string s1, s2;
        int cost;
        cin >> s1>> s2>>cost;
        int u= getId(s1);
        int v = getId(s2);
        adj[u].push_back({v,cost});
        adj[v].push_back({u,cost});
        
    }

    int p1;
    cin >>p1; 

    vector <pair<int , int >> port1;
   

    for (int i=0 ;i< p1; i++)
    {
        string portname;
        int cost ;
        cin >> portname >> cost;

        port1.push_back({getId(portname), cost});

    }
    int p2; cin >> p2;

      vector <pair<int , int >> port2;

 for (int i=0 ;i< p2; i++)
    {
        string portname;
        int cost ;
        cin >> portname >> cost;

        port2.push_back({getId(portname), cost});

    }

    for (auto e1: port1)
    {
        for (auto e2: port2)
        {
            int u = e1.first;
            int v= e2.first;
            long long totaltoll =e1.second +e2.second;

            adj[u].push_back({v, totaltoll});
            adj[v].push_back({u, totaltoll});
        }
    }


    vector <int > dist(100000, INF) ;
    vector <int > parent(10000, -1) ;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  string source, dest;
  cin >> source >> dest;

int src= getId(source);
int dst = getId(dest);

dist[src]= 0 ;
pq.push({0, src});

while (!pq.empty())
{

    auto u= pq.top();
      pq.pop();
    int curcost = u.first;
    int curnode = u.second;

    if (curcost >dist[curnode]) continue;
  
    for (auto e: adj[curnode])
    {
        int nextnode = e.first;
        int cost = e.second;

        
        if (dist[nextnode]> curcost +cost)
        {
            dist[nextnode]= curcost +cost;
            parent[nextnode]= curnode;
            pq.push({dist[nextnode], nextnode});

        }
    }
}
vector <string  > path ;

for (int i= dst; i !=-1; i=parent[i])
{
path.push_back(id_to_name[i]);

}
cout << "ans" <<" ";
reverse(path.begin(), path.end());
for (string p:path )
{
    cout << p << " ";
}


cout << dist[dst]<< endl;
    
}
