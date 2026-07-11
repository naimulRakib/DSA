

#include <iostream>

#include <algorithm>
#include <queue>
#include <vector>
using namespace std ; 

const int INF = 1e7;

int main()

{

     int n,m, k ;

     cin >>n >> m>> k ;

     vector <vector <vector <int > >>adj (n+1);



     for (int i = 0 ; i < m ; i++)

     {

        int u,v,w;

        cin >> u>> v>>w;

        adj[u].push_back({v,w});
        adj[v].push_back({u,w});

    
     }



     vector <vector <int >>dist (n+1, vector<int >(k+1, INF));
     priority_queue<vector <int >, vector <vector<int >>, greater<vector <int >>>pq;


dist[1][0]= 0;
pq.push({0,1,0});

while (!pq.empty())
{
    auto pqnode = pq.top();
    pq.pop();

    int curcost = pqnode[0];
    int curnode= pqnode[1];
    int couponused =  pqnode[2];

    if (curcost >dist[curnode][couponused]) continue;
    for (auto a: adj[curnode])
    {
        int v= a[0];
        int cost = a[1];


    
  
        
            if (dist[v][couponused]> curcost +cost)
            {
                dist[v][couponused]= curcost +cost; 
                pq.push({
                    dist[v][couponused], v, couponused
                });


            }

            if (couponused<k)
            {
                if (dist[v][couponused+1]> curcost +cost/2)
                {
                    dist[v][couponused+1]=curcost +cost/2;
                    pq.push({dist[v][couponused+1], v, couponused+1});

                }
            }

        
    

    }

}
int ans = INF;
for (int i = 0; i <=k ; i++)
{
    ans = min(ans , dist[n][i]);

}


cout << ans << endl;
}







// #include <iostream>
// #include <algorithm>
// using namespace std ; 
// const int INF = 1e7;

// int main()
// { int  n , m ;
//     cin >> n >> m ; 
//     vector <vector <int >>edges(m, vector <int >(3));
//      vector <vector <pair < int , int >>>adj(n+1);

//     for (int i= 0 ; i< m ; i++)
//     {
//         cin >> edges[i][0]>>edges[i][1]>> edges[i][2];
//         adj[edges[i][0]].push_back({edges[i][1],i});

//     }
// int k = 2; 
// // adj v, index
// //dist v, 012
// // edges u,v, cost
// // cost, v, coupon used 

//     vector <vector <int >>dist (n+1 , vector <int >(k+1, INF));

//     priority_queue<vector <int >, vector <vector <int >>, greater<vector<int >>>pq;
//     dist[1][0]= 0 ;
//     pq.push({0,1,0});

//     while (!pq.empty())
//     {
//         auto pr= pq.top();
//         pq.pop();
//         int d = pr[0];
//         int u =pr[1];
//         int j = pr[2];
//         for (auto neigh : adj[u])
//         {
//             int idx = neigh.second;
//             int v= neigh.first;
//             int cost = edges[ idx][2];

//             if (d+cost <dist[v][j])
//             {
//                 dist[v][j]= d+cost; 
//                 pq.push({dist[v][j], v, j});

//             }

//             if (j<k)
//             {
//                 int half = cost/2;
//                 if (d+half < dist[ v][j+1])
//                 {
//                     dist[v][j+1]= d+half;
//                     pq.push({dist[v][j+1], v, j+1});
//                 }
//             }

//         }
//     }

// int ans= 13231324;
// for (int i= 0 ; i<= k ; i++)
// {
//     ans = min (ans , dist[n][i]);
    
// }

// cout << ans << endl;
// return 0 ;


   
// }