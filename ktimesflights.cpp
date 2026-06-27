#include <vector>
#include <iostream>
#include <queue>
using namespace std;

typedef long long ll; 
const ll INF= 1e16; 


int main()
{
    int n,m,k ; 
    cin >> n >> m >> k ; 
    vector <tuple <int , int ,ll >> edges(m);

    for (int i = 0 ; i < m ; i++)
    {
        int a,b ; ll c;
        cin >> a >> b >> c; 
        edges[i]= {a,b,c};

    }

    int k = min(k, n-1);

    vector < array <ll ,2>> dp (n+1,{INF, INF} );

    dp [1][0]=0;

    for (int i = 0 ; i < k ; i++)

    {
       vector < array <ll ,2>> ndp = dp ; 

for (auto &[a,b,c] :edges)
{
if (dp[a][0]== INF)
{
    ndp[ b][0]= min(ndp[b][0], ndp[a][0]+c);

}

if (dp[b][1]== INF)
{
    ndp[ b][1]= min(ndp[b][1], ndp[a][0]+c/2);
    
}

if (dp[a][0]== INF)
{
    ndp[ b][1]= min(ndp[b][1], ndp[a][1]+c);
    
}


}

dp = ndp;

    }


    ll ans = min(dp[n][0], dp[n][1]);
    cout<< ans << endl;
    
}