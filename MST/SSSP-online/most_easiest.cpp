#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1e6;

int main()
{
    int n , m  ; 
cin >> n>> m ; 

vector <vector <pair <int  , double >>> adj (1000);
for (int i=0; i<m; i++)
{

    int u, v; double w; 
    cin >>u >> v >> w;

    adj[u].push_back({v,w});


}

vector <double > dist (1000, 0.0);
vector <int > parent (1000,-1);
priority_queue<pair<double, int>, vector<pair<double, int>>, less<pair<double, int>>> pq;
int src, dst;
cin >> src>> dst;

dist [src]=1.0;

pq.push({1.0, src});


while (!pq.empty())
{
    auto curpq= pq.top();
    pq.pop();
double curcost = curpq.first;
    int curnode = curpq.second;


    if (curcost < dist[curnode] ) continue;

    for (auto a: adj[curnode])
    {
        int u = a.first;
        double cost = a.second;
        if (curcost *cost > dist[u])
        {

            dist[u ] = curcost *cost;
            parent[u]= curnode;
            pq.push({dist[u], u});


        }
    }
}

cout << dist[dst]<< endl;

}