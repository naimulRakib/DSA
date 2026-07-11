#include <iostream>
#include <vector>
#include <algorithm>
#include <array> // Required for std::array

using namespace std;
const int INF = 1e8;

int main()
{
    int n,m,k , maxcoupons;
    cin >> n>> m>>k >> maxcoupons ;
    vector <array <int  ,3 >> edges (m);
    for (int i= 0 ; i <m ; i++)
    {
        cin >> edges[i][0] >> edges[i][1] >> edges[i][2];
    }

    vector <vector <int >> dist (n+1, vector <int >(maxcoupons+1, INF));

    dist [1][0]=0;
    for (int i= 0 ; i < k; i++)
    {
        vector<vector <int >> nextdist = dist ; 
      for (int j=0; j<m; j++)
      {
        int u = edges[j][0];
        int v = edges[j][1];
        int w= edges[j][2];

        for (int l =0; l <=maxcoupons; l++)
        {
            if (dist[u][l ]!= INF)
            {
                nextdist[v][l] = min(dist[u][l]+w, nextdist[v][l]);
                if (l<maxcoupons)
                {
     nextdist[v][l+1] = min(dist[u][l]+w/2, nextdist[v][l+1]);
                }
            }
        }

      }
      dist = nextdist;

    }
int ans = INF;

    for (int i=0 ; i<=maxcoupons; i++)
    {
        ans = min (ans , dist[n][i]);
    }

    if (ans !=INF)
    {
        cout << ans << endl;
    }
    else
    {
        cout <<"not possible " << endl;
    }
}