#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll; 

int main ()
{
    int n, m ; 
    cin >> n , m ; 
   vector <tuple <int ,int , ll>> edges(n+1);

    for (int i=0 ; i< m ; i++)
    {
  int a, b; ll c; 
  cin >> a >>b >>c; 
  edges[i]={a,b,c};

    }
vector <ll>dist (n+1, 0);
vector <int > par (n+1,-1);
int last = -1;

for (int i=0 ; i<n; i++)
{
    for (auto [a,b,c]: edges)
    {
        if (dist[ b]> dist[a]+c)
        {
            dist[b]= dist[a]+c;
            last= b;
            par[b ]= a;
        }
    }
}

if (last==-1)
{
    cout<< " no neg cycle "<< endl;
    return 0 ; 

}

int x= last ;
for (int i=0; i< n ; i++)
{
    last =par[last];

}

vector <int > cycle ; 
int cur = x;

while (cur !=x)
{cycle.push_back(cur );
    cur = par[cur ];

}
cycle.push_back(x);

}