#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;


vector <int >parent ;

int find(int x) {
    if (parent[x] == x)
        return x;
    parent[x] = find(parent[x]);
    return parent[x];
}

bool unite(int x, int y) {
    int rootx = find(x);
    int rooty = find(y);

    if (rootx != rooty) {
        parent[rootx] = rooty;
        return true;
    } else
        return false;
}

void resetparent(int n) {
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}


vector <array<int , 2>> points;

vector <array <int,3>> edges;
vector <array <int,3>> edges2;
// 5 0,1,2,3,4
//points 
set <int > states;



int calcCost(int idx1, int idx2)
{
    int calc = sqrt ((points[idx1][0]-points[idx2][0])*(points[idx1][0]-points[idx2][0])+(points[idx1][1]-points[idx2][1])*(points[idx1][1]-points[idx2][1]) );
    return calc;

}


void consecutiveedges(int index, int n)
{
    vector <array <int ,2>> order;

    for (int i=0; i<n; i++)
    {
        order.push_back({points[i][index], i});

    }

    sort(order.begin(), order.end());  
    for(int i= 0 ; i<n-1; i++)
    {
        int idx1=order[i][1];

        int idx2=order[i+1][1];

        int cost = calcCost(idx1, idx2);
        edges.push_back({cost,idx1, idx2});


    }

}

void buildedges(int n)
{
    consecutiveedges(0, n);
    consecutiveedges(1, n);

}


int main()
{
    int n,r;//most dist.
    cin >>n >> r;

    
for (int i=0 ; i< n ; i++)
{
    int x,y;
    cin >> x>> y;

    points.push_back({x,y});

}

int roadcost=0;
int railcost= 0;
int railline=0;



buildedges(n);
sort (edges.begin(), edges.end());

resetparent(n);

for (auto &e: edges)
{
    int a,b,c ;
    a= e[0];
    b=e[1];
    c=e[2];
   if (unite(b,c))

    {
       
     {edges2.push_back ({a,b,c});}
  

}

}
for (auto e: edges2)
{
    if (e[0]<=r)
    {roadcost+= e[0];
        
    }
    else {
        railcost +=e[0];
railline ++;

    }

}
cout << railline+1 <<" "<< roadcost << " " << railcost ; 
cout <<endl;


}