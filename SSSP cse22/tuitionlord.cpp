#include <iostream>
using namespace std;
typedef long long ll ; 
vector <tuple<int , int , ll > > State; 


int main()
{
ll k;
int n,x;
cin >> k >> n >> x ;
vector <vector <tuple <int , int ,ll >>> adj(n+1);// to, time ,cost 
for (int i=0 ; i< x ; i++)
{
int u, v, t,c;
cin >> u >> v >> t >> c;
adj[u].push_back({v,t,c});
adj[v].push_back({u,t,c});




}
int s, d; 
cin >> s>> d; 
const ll inf =1e18 ; 
vector<ll> dist (n+1, inf);
vector<int > time (n+1, inf);
vector <int > par (n+1, inf );

priority_queue<State, vector <State>, greater<State>> pq;

dist [s]=0;
time[s]=0;
pq.push({0, 0, });



}