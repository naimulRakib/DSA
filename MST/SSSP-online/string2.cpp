#include <iostream>
#include <algorithm>
#include <map>
using namespace std ; 
const int INF = 1e8;
int main (){
    int n , m ; 
    cin >> n >> m ;
    map<string, int> name_to_id;
    map<int, string> id_to_name;
    int current_id= 1;
    
auto getId = [&](string s) {
        if (name_to_id.find(s) == name_to_id.end()) {
            name_to_id[s] = current_id;
            id_to_name[current_id] = s;
            current_id++;
        }
        return name_to_id[s];
    };


    vector <int >airticket(n+1) ; 

    for (int i = 1 ; i <= n ; i++)
    {
string s; int cost;
cin >> s >> cost;
int id = getId(s);
airticket[id]= cost;
    }

vector<vector <pair <int , int >>> adj(n+1);
for (int i=0; i<m; i++)
{
    string s1, s2;
    int cost;
    cin >> s1>> s2>> cost ;
    int id1 = getId(s1);
    int id2 = getId(s2);
    adj[id1].push_back({id2,cost+airticket[id2]});
    adj[id2].push_back({id1,cost+airticket[id1]});


}


vector <int >dist(n+1, INF);
vector <int > parent(n+1, -1);

priority_queue<pair<int , int>, vector <pair <int , int >>, greater <pair <int , int >>>pq;
string source, dest;
cin >> source >> dest;
int src = getId(source);
int dst = getId(dest);
dist[src]= 0 ;
pq.push({0, src});
while (!pq.empty())
{ auto curpq= pq.top();
    pq.pop();

    int curnode =curpq.second;

    int curcost = curpq.first;
if (curcost > dist[curnode])
continue;



    for (auto a: adj[curnode])
    {
    int v= a.first;
    int cost = a.second;
    if (dist[v]> curcost+cost)
    {
        dist[v]= curcost+cost;

        parent[v]= curnode;

        pq.push({dist[v], v});
    }
    }



}

cout << dist [dst]<< endl;


}

