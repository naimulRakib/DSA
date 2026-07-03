#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>
#include <functional>

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
vector <array <int , 4>> edges;




int main()
{ int n,m;
   int edgecount =0 ;
int primaryproduct=1;

    cin >> n >> m ;

    for (int i=0 ; i<m ; i++)
    {
        int a,b,c;
        cin >>a>>b >> c;
        edges.push_back({c,a,b,i});

    }
    sort(edges.begin(), edges.end(),[](const array <int ,4> &a, const array <int , 4> &b)
    {
return a[0]> b[0];
    }

);
vector <bool > nodes(n,false);
resetparent (n);

set<int > unique;

    for (auto e: edges )
    {
        if (unite(e[1],e[2]))
        {
            nodes[e[3]]= true;

edgecount ++;
primaryproduct*= e[0];


        }
    }
    cout <<edgecount<<endl;
 
    if (edgecount !=n-1)
    {
        cout<< '-1'<< endl;

    return 0;
    }
int best = primaryproduct;


for (auto e: edges)
{ int current = 1;
    
    int edgecount =0;
   resetparent(n);

    if (!nodes[e[3]])
    {

        if(unite(e[1], e[2]))
        {
            current =e[0];
            edgecount++;

        }


        for (auto e: edges)
        {
if (unite(e[1], e[2])){
    current *= e[0];
    edgecount++;
    

}



    }}
if (edgecount == n-1)
unique.insert(current);



 
}


cout <<primaryproduct<<endl;
}
