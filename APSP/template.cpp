#include <iostream>
#include <vector>
#include <array>
#include <climits>

using namespace std;

const int INF = 1e6;



void floydWarshall(int n, vector<array<int ,3>> &edges, bool directed,
                    vector<vector<int >> &dist, vector<vector<int>> &nxt)
{
    dist.assign(n + 1, vector<int >(n + 1, INF));
    nxt.assign(n + 1, vector<int>(n + 1, -1));

    for (int i = 1; i <= n; i++) {
        dist[i][i] = 0;
        nxt[i][i] = i;
    }

    for (auto &e : edges) {
        int u = e[0], v = e[1];
        int  w = e[2];

        if (w < dist[u][v]) {
            dist[u][v] = w;
            nxt[u][v] = v;
        }
        if (!directed && w < dist[v][u]) {
            dist[v][u] = w;
            nxt[v][u] = u;
        }
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            if (dist[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (dist[k][j] == INF) continue;
                int  cand = dist[i][k] + dist[k][j];
                if (cand < dist[i][j]) {
                    dist[i][j] = cand;
                    nxt[i][j] = nxt[i][k];
                }
            }
        }
    }
}


vector<int> getPath(int u, int v, vector<vector<int >> &dist, vector<vector<int>> &nxt)
{
    vector<int> path;
    if (dist[u][v] == INF) return path;

    int cur = u;
    path.push_back(cur);
    while (cur != v) {
        cur = nxt[cur][v];
        path.push_back(cur);
    }
    return path;
}


bool hasNegativeCycle(int n, vector<vector<int >> &dist)
{
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] < 0) return true;
    }
    return false;
}

// sort(costs.rbegin(), costs.rend());

// 2020 section c: dsa lab

// int main()
// {
// int n , m , k; 
// cin >> n >> m >> k;
// vector <int > cap (n+1);

// for (int i= 1; i<= n ; i++)
// {
//     cin >> cap[i];

// }
// vector <bool > maintainance(n+1);

// for (int i=1; i<=n ;i++)
// {
//     if (cap[i]==-1){
//         maintainance[i]= true;
//     }
// }

// vector <array <int , 3>> edges;
// for (int i= 0 ; i<m ; i++)
// {
//     int u,v,w ; 
//     cin >>u >>v >>w;
//     if (maintainance[u]|| maintainance[v]) continue;
//     edges.push_back({u,v,w});

    
// }
// vector <vector <int > > dist;
// vector <vector <int > > nxt;
// floydWarshall(n, edges, false, dist, nxt);

// int q;
// cin >> q;
// vector <int > queries(q+1);

// for (int i= 0 ; i <q; i++)
// {
// cin >> queries[ i];

// }



// for ( int i= 0 ; i< q; i++)
// {

//     int start = queries[i];
//     vector <int > capacity = cap;
//     vector <int >ans ;
//     for ( int j= 0 ; j<k ; j++)
//     {
//         int bestdist = INF;
//         int bestlab =-1;
//         for (int l = 1;l<= n; l++)
//         {
//             if (maintainance[l]) continue;
//             if (capacity[l]<=0) continue;
        
// if (dist[start][l] == INF) continue;
//             if(dist[start][l] < bestdist)
//             {
//                 bestdist = dist[start][l];
//                 bestlab = l;
//             }

    
//         }
//         if (bestlab == -1) {ans.push_back (-1);
//         }
//         else {ans.push_back(bestdist);
//         capacity[bestlab]--;}



//         }



// for (int j= 0 ; j< ans.size() ; j++)
// {
//     cout << ans[j]<<" ";

// } 

// cout <<"\n";
//    }


//    cout << endl;

// }



// 22 b section , kingdom
// int main()
// {
//     int n , m , k ;
//     cin >> n>> m>> k ;
//     vector <int > current (n+1);
//     vector <int > target(n+1);

//     for (int i= 1 ; i<=n ; i++)
//     {
// cin >>current [ i];

//     }
//       for (int i= 1 ; i<=n ; i++)
//     {
// cin >>target [ i];

//     }


// vector <array <int , 3>> edges;
//     for (int i = 0; i<m ; i++)
//     {
//         int u,v,w;
//         cin >> u >>v >>w
//     ;
//     edges.push_back({u,v,w})
//     ;


//     }


//     vector <vector <int >> dist ;
//     vector <vector <int >> nxt;


//     floydWarshall(n, edges, true, dist, nxt);
//     vector <int > costs;


//     for (int i=1; i<= n ; i++)
//     {
//         int distance = dist[current[i]][target[i]];

//         if (distance !=INF)
//         costs.push_back(distance);


//     }

//     sort(costs.rbegin(), costs.rend());
//     int totalcost = 0;
//     int multiplier =1;
//     int cnt= 0;
//     for (int i=0 ;i<costs.size();i++)
//     {

//         totalcost +=costs[i]*multiplier;

//         cnt++;

//         if (cnt==k)
//         {
//             multiplier*=2;
//             cnt =0;

//         }

//     }

//     cout <<totalcost << endl;
// }




// 22 a tuition lord's meet
int main()
{
    int n, m ,k , x;
    cin >> n>> m>> k>> x;
    vector <int > a(k);
    for (int i= 0 ; i<k ; i++)
    {
        cin>> a[i];

    }

    vector <int > hrs(k);


    for (int i=0;i < k; i++)
    {
        cin >> hrs[i];

    }

    vector <array <int , 3> > edges;
    for (int i=0;i < m; i++)

{

    int u,v,w;
    cin >> u>> v>>w;
    edges.push_back({u,v,w});
}

vector <vector <int>> dist ;
vector <vector <int >> nxt;

floydWarshall(n, edges,false, dist, nxt);

// best city , min cost , best time
int bestcity=-1;
int mincost = INF;
int besttime = 0 ;


for (int i= 1 ; i<=n; i++)
{ int current_total_cost =0;
int currenttime = 0 ;

    bool possible =true;
    for (int j =0 ; j<k ; j++)
    {
        int distance = dist [a[j]][i];

        if (distance > x)
       { possible= false;
        break ;}
        else 
        {
            current_total_cost+=hrs[j] *distance;

        }

 currenttime = max (currenttime, distance);
 
   

    }


    if (possible && current_total_cost< mincost)
    {
        mincost = current_total_cost;
        
        bestcity = i;
        besttime = currenttime;
    }


}
cout << bestcity << " " << mincost << " " << besttime << "\n";


}