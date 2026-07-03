#include <iostream>
using namespace std;
long long INF = 1e18;
const int MAXN = 1005;

vector <pair<int , int >> adj [MAXN];

long long dist[MAXN];
int cnt [MAXN];
bool isqueue[MAXN];
bool blocked [ MAXN];

bool ssfp(int source , int nodecounts)
{

   
    fill (dist, dist +nodecounts+1, INF);

 fill (cnt ,cnt +nodecounts+1, 0);
  fill (isqueue, isqueue +nodecounts+1,false);

 fill (blocked, blocked +nodecounts+1, false);

 queue<int >q;
 dist[source]= 0 ; 
 q.push(source);//how much it has been enqueue ;

isqueue[source]= true ;

 cnt[source ]= 1;

while (!q.empty())
{
    int u =q.front();
    q.pop();
   isqueue[u]= false;

for (auto edges: adj[u])
{
    int v= edges.first;
    int w= edges.second;

    if (dist[v]!= INF && dist[v]> dist[u]+w)
    {
        dist[v]= dist[u]+w;

    }

    if (!isqueue[v])
    {
        isqueue[v]= true;
            cnt[v]++;
            if (cnt[v]>nodecounts)
            {
                return false;

            }
        q.push(v);
    

    }

}

}
return false ; 

}

int main()
{
int n , m , k , b, e;
cin >> n >> m >> k >> b >> e;
vector <int > capitals(k), posts(e);

for (int i = 0; i < k; i++)
{
    cin >> capitals[i];
}
for (int i =0 ; i <b; i++)
{
int mblocked;
cin >> mblocked;
blocked[mblocked]= true;
}

for (int i= 0; i<e;i++)
{
  cin >>posts[ i];
}


for ( int i=0 ; i< m;i++)
{
int a,b,c;
cin >>a>>b >> c;

 if (!blocked[a] && !blocked[ b])
 {
    adj[a].push_back({b,c});


 }
}

for (int cap: capitals )
{
    adj[0].push_back({cap, 0});

}

bool negcycle = ssfp(0, n+1);
if(negcycle)
{
    cout << "Abyss detected " << endl;
}
else {
    for (int post : posts)
    {
        cout << dist [ post] ;
       

    }
}
cout <<endl;
 
}

