#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <set>

using namespace std;

vector <int > safecity;
vector <int >parent ;
vector <bool> risky ;

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

        safecity[rooty]+=safecity[rootx];

        return true;
    } else
        return false;
}

void resetparent(int n) {
    parent.resize(n + 1);
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        safecity[i]= risky[i]? 0:1;    
        
    }
}
vector <array <int , 3>> edges;



int main ()
{
    int n , m , p; 
    cin >> n >> m >> p ; 

    int r;
    cin >>r;

    risky.resize(n, false);
    safecity.resize(n);

    
    for (int i=0 ; i < r; i++)
    { int a;
        cin >>a;

        risky[a]= true ;

    }


    for (int i=0 ; i < m; i++)
    {
        int x,y,z;
        cin >>x>> y >>z;

        if (!risky[x] && !risky[y])
        {
            edges.push_back({z,x,y});
        }
        else if (!risky[x] && risky[y])
        {
            edges.push_back({z+p, x,y});

        }

         else if (risky[x] && !risky[y])
        {
            edges.push_back({z+p, x,y});

        }
        else 
        {
            edges.push_back({z+2*p, x,y});

        }
    }



    int totalsafe= n-r;
sort(edges.begin(), edges.end());

resetparent(n);
    vector <pair<int , int >> safeedges;

int totalcost = 0 ;
int allisconnected=0;


    for (auto e:edges)
    {
        if (!risky[e[1]] && !risky[e[2]])
        {

            if (unite(e[1], e[2]))
            {
                safeedges.push_back({e[1],e [2]});

                totalcost +=e[0];


            }
        }

        if (safecity[find(e[1])]== totalsafe)
        {
            allisconnected=1;

        }
    }

    if (!allisconnected)
    {
        for (auto e: edges)
        {
             if (unite(e[1], e[2]))
            {
                safeedges.push_back({e[1],e [2]});

                totalcost +=e[0];


            }
            if (safecity[find(e[2])]== totalsafe)
            {
                allisconnected=1;
                break;
            }
        }
    }




    cout << totalcost << endl;
    cout << allisconnected << endl;


}