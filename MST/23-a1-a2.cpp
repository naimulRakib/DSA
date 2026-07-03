
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
//confirmed
using namespace std;
vector <int >parent ;

vector <array <int , 3>> edges;


//confirmed

int find (int x)
{
    if (parent[x]==x)
    return x;

parent[x]= find(parent[x]);

return parent [x];


}

bool unite (int x, int y)
{
    int rootx= find(x);
    int rooty = find(y);

    if (rootx!=rooty)
    {
        return parent[rootx]= rooty;
        return true;


    }

    else 
    {
        return false ;

    }
}

void resetparent (int n)
{
    parent.resize(n);

    for (int i=1; i<= n; i++)
    {
        parent[i]=i;

    }
}

int main()
{

int n; 
cin >>n ;
vector<int > p(n) ; 

for (int i=0 ; i< n; i++)
{
cin >>p[i];
}
int m;

cin >> m;
for (int i=0 ; i < m ; i++)
{
    int u,v,w;
    cin >>u >> v >> w;

    edges.push_back({w,u,v});

    
}

for (int i=1; i<=n; i++)
{
    edges.push_back({p[i-1], 0, i});

}
sort(edges.begin(), edges.end());

int totalcost=0;
resetparent(n);

for (auto e: edges)
{
    if (unite (e[1], e[2]))
    {
totalcost+=e[0];

    }
}
cout << totalcost << endl;

}