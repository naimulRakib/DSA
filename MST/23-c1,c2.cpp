#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <cmath>
using namespace std ;

vector <int> parent;

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

    for (int i=0; i< n; i++)
    {
        parent[i]=i;

    }
}
 vector <array<int , 3>> points;
 vector <array <int ,3>> edges;
  

// n, m 
// x1, y1 ,z1

int realcalc(int index1, int index2)
{
    int cost = min({abs (points[index1][0]-points[index2][0]), abs (points[index1][1]-points[index2][1]),abs (points[index1][2]-points[index2][2])});
    return cost ;
}

void consec(int idx)
{
vector<pair <int , int > >order;

for (int i=0 ; i< points.size(); i++)
{
order.push_back({points[i][idx],i});

}

sort(order.begin(), order.end());

for ( int i = 0 ; i<order.size()-1; i++)
{
    int index1= order[i].second;
    int index2= order[i+1].second;
int realcost = realcalc(index1, index2);
edges.push_back({realcost,index1,index2});


}

}

void buildedges()
{
    consec(0);
    consec(1);
    consec(2);


}



int main()
{
 int n;


    cin >> n ; 

   

    for (int i=0 ; i< n; i++)
    {
        int x, y, z;
        cin >> x>> y>>z;

        points.push_back({x,y,z});


    }
    buildedges();
    sort(edges.begin(), edges.end());
resetparent (n);
int totalcost =0 ;

    for (auto e:edges)
    {

if (unite(e[1], e[2]))

{
totalcost+=e[0];

}

    }

cout <<totalcost << endl;


    
}